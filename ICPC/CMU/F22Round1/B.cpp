#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

// Vanilla Segment Tree
// O(n log n) preprocessing, O(log n) query, O(log n) update
struct SumInt {
    using T = long long;
    const T e = 0;
    T f(T a, T b) const { return a + b; }
};
struct MaxInt {
    using T = long long;
    const T e = LLONG_MIN;
    T f(T a, T b) const { return max(a, b); }
};
struct MinInt {
    using T = long long;
    const T e = LLONG_MAX;
    T f(T a, T b) const { return min(a, b); }
};
struct GCDInt {
    using T = long long;
    const T e = 0;
    T f(T a, T b) const {
        if (a == 0)
            return b;
        if (b == 0)
            return a;
        return gcd(a, b);
    }
};
struct XORInt {
    using T = long long;
    const T e = 0;
    T f(T a, T b) const { return (a ^ b); }
};
template <class B>
struct SegTree : public B {
    using T = typename B::T;
    int n;
    vector<T> tree;
private:
    void _build(const vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
            return;
        }
        int tmid = tl + (tr - tl) / 2;
        _build(a, v*2, tl, tmid);
        _build(a, v*2+1, tmid+1, tr);
        tree[v] = B::f(tree[v*2], tree[v*2+1]);
    }
    void _update(int v, int tl, int tr, int pos, T val) {
        if (tl > tr || pos > tr || pos < tl)
            return;
        if (pos == tl && pos == tr) {
            tree[v] = val;
            return;
        }
        int tmid = tl + (tr - tl) / 2;
        _update(v*2, tl, tmid, pos, val);
        _update(v*2+1, tmid+1, tr, pos, val);
        tree[v] = B::f(tree[v*2], tree[v*2+1]);
    }
    T _query(int v, int tl, int tr, int l, int r) const {
        if (l > r || tr < l || tl > r)
            return B::e;
        if (tr <= r && tl >= l)
            return tree[v];
        int tmid = tl + (tr - tl) / 2;
        return B::f(_query(v*2, tl, tmid, l, min(r, tmid)),
                    _query(v*2+1, tmid+1, tr, max(l, tmid+1), r));
    }
    T _get(int v, int tl, int tr, int pos) const {
        if (tl == tr)
            return tree[v];
        int tmid = tl + (tr - tl) / 2;
        if (pos <= tmid)
            return _get(v*2, tl, tmid, pos);
        else
            return _get(v*2+1, tmid+1, tr, pos);
    }
public:
    SegTree(int n_) : n(n_) {
        tree.assign(4*n, B::e);
        vector<T> a(n, B::e);
        _build(a, 1, 0, n-1);
    }
    SegTree(const vector<T>& a) : n(a.size()) {
        tree.assign(4*n, B::e);
        _build(a, 1, 0, n-1);
    }
    friend ostream& operator<<(ostream& os, const SegTree& st) {
        for (int i = 0; i < st.n; ++i)
            os << st.get(i) << (i == st.n-1 ? "\n" : " ");
        return os;
    }
    void build(const vector<T>& a)   { _build(a, 1, 0, n-1); }
    void update(T val, int pos)      { _update(1, 0, n-1, pos, val); }
    T query(int l, int r)            { return _query(1, 0, n-1, l, r); }
    T get(int pos)                   { return _get(1, 0, n-1, pos);  }
    T operator[](int pos)            { return get(pos); }
};

int tt = 1, n, m, q;

void solve() {
    cin >> n >> q;
    vector<vector<array<int,2>>> query(n);
    for (int i = 0; i < q; i++) {
        int l, r, j;
        cin >> l >> r >> j;
        l--, r--, j--;
        query[j].push_back({l,r});
    }
    vector<bool> vis(n, 0);
    SegTree<SumInt> anc(n);
    vector<int> ord;
    set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(i);
    function<bool(int)> dfs = [&](int v) {
        st.erase(v);
        vis[v] = true;
        anc.update(1, v);
        for (int i = 0; i < query[v].size(); i++) {
            auto l = st.lower_bound(query[v][i][0]);
            auto r = st.upper_bound(query[v][i][1]);
            vector<int> child;
            if (anc.query(query[v][i][0], query[v][i][1]) != 1)
                return false;
            for (auto it = l; it != r; it++) {
                int u = *it;
                child.push_back(u);
            }
            for (int u : child) {
                if (vis[u])
                    continue;
                bool ok = dfs(u);
                if (!ok)
                    return false;
            }
        }
        anc.update(0, v);
        ord.push_back(v);
        return true;
    };
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            bool ok = dfs(i);
            if (!ok) {
                cout << "-1\n";
                return;
            }
        }
    }
    reverse(ord.begin(), ord.end());
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[ord[i]] = i+1;
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

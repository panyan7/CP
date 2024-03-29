#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

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
template <class B>
struct SegTree : public B {
    using T = typename B::T;
    int n;
    vector<T> tree;
    vector<T> add;
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
    void _push(int v) {
        tree[v*2  ] += add[v];
        tree[v*2+1] += add[v];
        add[v*2  ] += add[v];
        add[v*2+1] += add[v];
        add[v] = 0;
    }
    void _update(int v, int tl, int tr, int l, int r, T val) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            tree[v] += val;
            add[v] += val;
            return;
        }
        _push(v);
        int tmid = tl + (tr - tl) / 2;
        _update(v*2, tl, tmid, l, min(r, tmid), val);
        _update(v*2+1, tmid+1, tr, max(l, tmid+1), r, val);
        tree[v] = B::f(tree[v*2], tree[v*2+1]);
    }
    T _query(int v, int tl, int tr, int l, int r) {
        if (l > r || tr < l || tl > r)
            return B::e;
        if (tr <= r && tl >= l)
            return tree[v];
        _push(v);
        int tmid = tl + (tr - tl) / 2;
        return B::f(_query(v*2, tl, tmid, l, min(r, tmid)),
                    _query(v*2+1, tmid+1, tr, max(l, tmid+1), r));
    }
    T _get(int v, int tl, int tr, int pos) {
        if (tl == tr)
            return tree[v];
        _push(v);
        int tmid = tl + (tr - tl) / 2;
        if (pos <= tmid)
            return _get(v*2, tl, tmid, pos);
        else
            return _get(v*2+1, tmid+1, tr, pos);
    }
public:
    SegTree(int n_) : n(n_) {
        tree.assign(4*n, B::e);
        add.assign(4*n, 0);
        vector<T> a(n, B::e);
        _build(a, 1, 0, n-1);
    }
    SegTree(const vector<T>& a) : n(a.size()) {
        tree.assign(4*n, B::e);
        add.assign(4*n, 0);
        _build(a, 1, 0, n-1);
    }
    friend ostream& operator<<(ostream& os, SegTree& st) {
        for (int i = 0; i < st.n; ++i)
            os << st.get(i) << (i == st.n-1 ? "\n" : " ");
        return os;
    }
    void build(const vector<T>& a)   { _build(a, 1, 0, n-1); }
    void update(T val, int l, int r) { _update(1, 0, n-1, l,   r,   val); }
    void update(T val, int pos)      { _update(1, 0, n-1, pos, pos, val); }
    T query(int l, int r)            { return _query(1, 0, n-1, l, r); }
    T get(int pos)                   { return _get(1, 0, n-1, pos);  }
    T operator[](int pos)            { return get(pos); }
};

int tt = 1, n, m, q;

void solve() {
    cin >> n >> q;
    vector<int> res(n);
    vector<ll> c(n, 0);
    SegTree<MinInt> cnt(c);
    vector<vector<array<int,2>>> query(n);
    for (int i = 0; i < q; i++) {
        int l, r, j;
        cin >> l >> r >> j;
        l--, r--, j--;
        cnt.update(1, l, r);
        cnt.update(-1, j);
        query[j].push_back({l,r});
    }
    set<int> s;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) {
            cnt.update(1e9, i);
            q.push(i);
        }
    }
    int r = 1;
    while (!q.empty()) {
        int v = q.front();
        res[v] = r;
        r++;
        q.pop();
        for (int j = 0; j < query[v].size(); j++) {
            cnt.update(-1, query[v][j][0], query[v][j][1]);
            cnt.update(1, v);
        }
        if (q.empty()) {
            if (cnt.query(0, n-1) > 0)
                break;
            // binary search on segtree to find the next 0
            int lo = -1, hi = n;
            while (lo + 1 < hi) {
                int mid = lo + (hi - lo) / 2;
                if (cnt.query(0, mid) == 0)
                    hi = mid;
                else
                    lo = mid;
            }
            if (hi >= n)
                break;
            cnt.update(1e9, hi);
            q.push(hi);
        }
    }
    if (r <= n)
        cout << "-1\n";
    else {
        for (int i = 0; i < n; i++)
            cout << res[i] << " ";
        cout << "\n";
    }
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

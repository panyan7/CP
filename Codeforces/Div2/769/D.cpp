#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
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

int tt = 1, n, m, k;
ll g[200005], res[200005];

// check long long
void solve() {
    cin >> n;
    vector<ll> a(n+1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    SegTree<GCDInt> st(a);
    int i = 1, j = 1;
    for (int i = 1; i <= n; i++) {
        res[i] = max(res[i], res[i-1]);
        j = max(j, i);
        ll g = st.query(i, j);
        while (j <= n && gcd(g, a[j]) > j-i+1) {
            g = gcd(g, a[j]);
            res[j] = max(res[j], res[i-1]);
            j++;
        }
        if (gcd(g, a[j]) == j-i+1)
            res[j] = max(res[j], res[i-1] + 1);
        else
            res[j] = max(res[i-1], res[j]);
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

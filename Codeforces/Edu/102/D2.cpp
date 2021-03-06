#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
struct MaxInt {
    using T = int;
    const T e = INT_MIN;
    T f(T a, T b) const { return max(a, b); }
};
struct MinInt {
    using T = int;
    const T e = INT_MAX;
    T f(T a, T b) const { return min(a, b); }
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

int t = 1, n, m, k;

void solve() {
    cin >> n >> m;
    vector<int> a(n), p(n+1, 0);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        a[i] = (s[i] == '+' ? 1 : -1);
        p[i+1] = a[i] + p[i];
    }
    SegTree<MaxInt> mx(p);
    SegTree<MinInt> mn(p);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l == 0 && r == n-1)
            cout << 1 << "\n";
        else {
            int lmax = mx.query(0, l-1);
            int lmin = mn.query(0, l-1);
            int rmax = mx.query(r+1, n) - p[r+1] + p[l];
            int rmin = mn.query(r+1, n) - p[r+1] + p[l];
            cout << max(lmax, rmax) - min(lmin, rmin) + 1 << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

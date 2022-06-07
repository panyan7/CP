#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

/* Segment tree with range assignment query and range sum query */
template <typename T>
struct SegTree {
    int n;
    vector<T> tree;
    vector<bool> mark;
private:
    void _build(const vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
            mark[v] = true;
            return;
        }
        int tmid = tl + (tr - tl) / 2;
        _build(a, v*2, tl, tmid);
        _build(a, v*2+1, tmid+1, tr);
        tree[v] = 0;
    }
    void _push(int v) {
        if (mark[v]) {
            tree[v*2] = tree[v*2+1] = tree[v];
            mark[v*2] = mark[v*2+1] = true;
            mark[v] = false;
        }
    }
    void _update(int v, int tl, int tr, int l, int r, T val) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            tree[v] = val;
            mark[v] = true;
            return;
        }
        _push(v);
        int tmid = tl + (tr - tl) / 2;
        _update(v*2, tl, tmid, l, min(r, tmid), val);
        _update(v*2+1, tmid+1, tr, max(l, tmid+1), r, val);
    }
    T _query(int v, int tl, int tr, int l, int r) const {
        if (l > r || tr < l || tl > r)
            return 0;
        if (mark[v] && tr >= r && tl <= l)
            return tree[v] * (r-l+1);
        int tmid = tl + (tr - tl) / 2;
        return _query(v*2, tl, tmid, l, min(r, tmid)) +
               _query(v*2+1, tmid+1, tr, max(l, tmid+1), r);
    }
    T _get(int v, int tl, int tr, int pos) const {
        if (tl == tr || mark[v])
            return tree[v];
        int tmid = tl + (tr - tl) / 2;
        if (pos <= tmid)
            return _get(v*2, tl, tmid, pos);
        else
            return _get(v*2+1, tmid+1, tr, pos);
    }
public:
    SegTree(int n_) : n(n_) {
        tree.assign(4*n, 0);
        mark.assign(4*n, false);
        vector<T> a(n, 0);
        _build(a, 1, 0, n-1);
    }
    SegTree(const vector<T>& a) : n(a.size()) {
        tree.assign(4*n, 0);
        mark.assign(4*n, false);
        _build(a, 1, 0, n-1);
    }
    friend ostream& operator<<(ostream& os, const SegTree& st) {
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

int tt = 1, n, m;

struct cmp {
    bool operator() (pll a, pll b) const {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
};

void solve() {
    cin >> n >> m;
    vector<ll> a(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    c = a;
    for (int i = 1; i < n; i++)
        if (a[i] > a[i-1])
            a[i] = a[i-1];
    vector<ll> b(n, 0);
    b[0] = 1;
    for (int i = 1; i < n; i++)
        if (a[i] < a[i-1])
            b[i] = 1;
    SegTree<ll> st(a);
    set<pll, cmp> trains;
    for (int i = 0; i < n; i++)
        if (b[i] == 1)
            trains.insert({a[i], i});
    while (m--) {
        int k, d;
        cin >> k >> d;
        k--;
        ll sk = st.get(k);
        if (d != 0) {
            c[k] -= d;
            if (c[k] < sk) {
                ll new_speed = c[k];
                auto it2 = trains.upper_bound({new_speed, n});
                int lo = (it2 == trains.end() ? n-1 : it2->second-1);
                auto it1 = trains.lower_bound({sk, k});
                trains.erase(it1, it2);
                trains.insert({new_speed, k});
                st.update(new_speed, k, lo);
            }
        }
        cout << trains.size() << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

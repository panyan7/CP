#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

// Range Minimum Query with sparse table
// O(nlogn) preprocessing, O(1) query
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
class RMQ : public B {
    using T = typename B::T;
    int n, lim;
    vector<vector<T>> spt;
private:
    void _build (const vector<T>& a) {
        spt.assign(lim+1, vector<T>(n, 0));
        for (int i = 0; i < n; ++i)
            spt[0][i] = a[i];
        for (int k = 1; k <= lim; ++k)
            for (int i = 0; i <= n-(1<<k); ++i)
                spt[k][i] = B::f(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
    }
public:
    RMQ(const vector<T>& a) : n(a.size()), lim(floor(log2(n)+1)) { _build(a); }
    T query(int i, int j) const {
        int k = floor(log2(j-i+1));
        T res = B::f(spt[k][i], spt[k][j-(1<<k)+1]);
        return res;
    }
};

int tt = 1, n, m, q;

void solve() {
    cin >> n >> q;
    vector<ll> a(n+1), b(n+1), d(n+1), p(n+1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        d[i] = a[i] - b[i];
    for (int i = 1; i <= n; i++)
        p[i] = p[i-1] + d[i];
    RMQ<MaxInt> stmx(p);
    RMQ<MinInt> stmn(p);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        ll check = stmx.query(l, r) - p[l-1];
        ll res = -(stmn.query(l, r) - p[l-1]);
        if (check > 0 || p[l-1] != p[r]) {
            cout << "-1\n";
        } else {
            cout << res << "\n";
        }
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

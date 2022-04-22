#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>
template <typename T>
class RMQ {
    vector<vector<T>> spt;
    int n, lim;
private:
    void _build (const vector<T>& a) {
        spt.assign(lim+1, vector<T>(n, 0));
        for (int i = 0; i < n; ++i)
            spt[0][i] = a[i];
        for (int k = 1; k <= lim; ++k)
            for (int i = 0; i <= n-(1<<k); ++i)
                spt[k][i] = min(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
    }
public:
    RMQ(const vector<T>& a) : n(a.size()), lim(floor(log2(n)+1)) { _build(a); }
    T query(int i, int j) const {
        int k = floor(log2(j-i+1));
        T res = min(spt[k][i], spt[k][j-(1<<k)+1]);
        return res;
    }
};


int tt = 1, n, m;

void solve() {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    vector<ll> p(n+2);
    for (int i = 1; i <= n; i++)
        p[i] = a[i-1]-p[i-1];
    unordered_map<ll, vector<ll>> mpo;
    unordered_map<ll, vector<ll>> mpe;
    for (int i = 1; i <= n; i += 2)
        mpo[p[i]].push_back(i);
    for (int i = 0; i <= n; i += 2)
        mpe[p[i]].push_back(i);

    vector<ll> b = p;
    for (int i = 0; i <= n; i += 2)
        b[i] = LLONG_MAX;
    RMQ mxo(b);
    b = p;
    for (int i = 1; i <= n; i += 2)
        b[i] = LLONG_MAX;
    RMQ mxe(b);
    ll res = 0;
    for (int i = 1; i <= n; i += 2) {
        int lo = i, hi = n+1;
        auto check = [&](int k) {
            if (mxo.query(i, k) < p[i] || mxe.query(i, k) < -p[i])
                return false;
            return true;
        };
        while (lo + 1 < hi) {
            int mid = lo+(hi-lo)/2;
            if (check(mid))
                lo = mid;
            else
                hi = mid;
        }
        auto it = upper_bound(mpo[p[i]].begin(), mpo[p[i]].end(), i);
        auto it2 = upper_bound(mpo[p[i]].begin(), mpo[p[i]].end(), lo);
        ll nm = (ll)distance(it, it2);
        res += nm;
        it = upper_bound(mpe[-p[i]].begin(), mpe[-p[i]].end(), i);
        it2 = upper_bound(mpe[-p[i]].begin(), mpe[-p[i]].end(), lo);
        nm = (ll)distance(it, it2);
        res += nm;
    }
    for (int i = 0; i <= n; i += 2) {
        int lo = i, hi = n+1;
        auto check = [&](int k) {
            if (mxe.query(i, k) < p[i] || mxo.query(i, k) < -p[i])
                return false;
            return true;
        };
        while (lo + 1 < hi) {
            int mid = lo+(hi-lo)/2;
            if (check(mid))
                lo = mid;
            else
                hi = mid;
        }
        auto it = upper_bound(mpe[p[i]].begin(), mpe[p[i]].end(), i);
        auto it2 = upper_bound(mpe[p[i]].begin(), mpe[p[i]].end(), lo);
        ll nm = (ll)distance(it, it2);
        res += nm;
        it = upper_bound(mpo[-p[i]].begin(), mpo[-p[i]].end(), i);
        it2 = upper_bound(mpo[-p[i]].begin(), mpo[-p[i]].end(), lo);
        nm = (ll)distance(it, it2);
        res += nm;
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

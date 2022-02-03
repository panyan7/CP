#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
ll dp[55][55];

void umin(ll& a, ll b) {
    a = min(a, b);
}

// check long long
void solve() {
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= 1000;
    }
    for (int i = 0; i < n; i++)
        cin >> b[i];
    auto check = [&](ll x) {
        vector<pll> c(n);
        for (int i = 0; i < n; i++)
            c[i] = {a[i], a[i] - b[i] * x};
        sort(c.begin(), c.end(), greater<pll>());
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = 1e14;
        dp[0][0] = 0;
        int l = 0;
        while (l < n) {
            int r = l;
            while (r < n && c[r].first == c[l].first)
                r++;
            for (int i = 0; i <= l; i++) {
                if (dp[l][i] >= 1e14)
                    continue;
                ll sm = dp[l][i];
                for (int j = l; j < r; j++) {
                    sm += c[j].second;
                }
                for (int j = l; j <= r; j++) {
                    if (j-l <= i) {
                        umin(dp[r][i+l-j+r-j], sm);
                    }
                    sm -= c[j].second;
                }
            }
            l = r;
        }
        for (int i = 0; i <= n; i++) {
            if (dp[n][i] <= 0)
                return true;
        }
        return false;
    };
    ll lo = 0, hi = 1e14;
    while (lo + 1 < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << "\n";
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

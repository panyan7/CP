#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
 
int tt = 1, n, m, k;
const int N = 2e5+10;
ll dp[N][25], a[N], l[N];
 
void solve() {
    ll x;
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    const ll INF = -1e18;
    ll res = 0;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        if (n - i >= k)
            dp[i][0] = max(dp[i][0], dp[i-1][0] + a[i] - x);
        res = max(res, dp[i][0]);
    }
    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[i-1][j-1] + a[i] + x;
            if (j <= i)
                dp[i][j] = max(dp[i][j], 0LL);
            if (n - i >= k - j)
                dp[i][j] = max(dp[i][j], dp[i-1][j] + a[i] - x);
            res = max(res, dp[i][j]);
        }
    }
    cout << res << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, ~0x3f, sizeof(dp));
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

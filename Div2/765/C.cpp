#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k, l;
int dp[505][505];

// check long long
void solve() {
    cin >> n >> l >> k;
    vector<int> d(n+1);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];
    d[n] = l;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    memset(dp, 0x3f, sizeof(dp));
    for (int j = 0; j <= k; j++)
        dp[n][j] = 0;
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j <= k; j++) {
            // dp[i][j] == i to end, remove j signs, don't remove i
            for (int t = i+1; t <= min(n, j+i+1); t++) {
                dp[i][j] = min(dp[i][j], (d[t] - d[i]) * a[i] + dp[t][j-(t-i-1)]);
            }
        }
    }
    cout << dp[0][k] << "\n";
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

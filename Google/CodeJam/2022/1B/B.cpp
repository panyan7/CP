#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k, p;

void solve() {
    cin >> n >> p;
    vector<vector<ll>> a(n, vector<ll>(p, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
    }
    vector<vector<ll>> dp(n, vector<ll>(2, 1e14));
    ll res = 0, cur = 0;
    dp[0][0] = 2 * a[0][p-1] - a[0][0];
    dp[0][1] = a[0][p-1];
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i][0], dp[i-1][0] + abs(a[i-1][0] - a[i][p-1]) + abs(a[i][p-1] - a[i][0]));
        dp[i][0] = min(dp[i][0], dp[i-1][1] + abs(a[i-1][p-1] - a[i][p-1]) + abs(a[i][p-1] - a[i][0]));
        dp[i][1] = min(dp[i][1], dp[i-1][0] + abs(a[i-1][0] - a[i][0]) + abs(a[i][p-1] - a[i][0]));
        dp[i][1] = min(dp[i][1], dp[i-1][1] + abs(a[i-1][p-1] - a[i][0]) + abs(a[i][p-1] - a[i][0]));
    }
    cout << min(dp[n-1][0], dp[n-1][1]) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    for (int ti = 1; ti <= tt; ti++) {
        cout << "Case #" << ti << ": ";
        solve();
    }
    return 0;
}

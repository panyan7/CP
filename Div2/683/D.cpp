#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
int dp[5005][5005];

// check long long
void solve() {
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]-1);
            dp[i][j] = max(dp[i][j], dp[i][j-1]-1);
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (a[i-1] == b[j-1] ? 2 : -2));
            res = max(res, dp[i][j]);
        }
    }
    cout << res << "\n";
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

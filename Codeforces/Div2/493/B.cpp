#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
int a[105], dp[105][105];

// check long long
void solve() {
    int b;
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int cnt = 0;
    int cost = 0;
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 == 0)
            cnt++;
        else
            cnt--;
        if (cnt == 0 && i < n) {
            for (int j = 0; j <= n; j++) {
                dp[i][j+1] = min(dp[i][j+1], dp[i-1][j] + abs(a[i] - a[i+1]));
            }
        }
        for (int j = 0; j <= n; j++) {
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */
    int res = 0;
    for (int i = 0; i <= n; i++) {
        if (dp[n][i] <= b)
            res = i;
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

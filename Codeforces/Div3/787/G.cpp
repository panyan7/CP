#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
const int MAXN = 255;
const int MAXM = 255;
int dp[MAXN][MAXM][MAXM], a[MAXN], p[MAXN];

void chkmin(int& a, int b) { a = min(a, b); }

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        p[i] = p[i-1] + a[i];
    memset(dp, 0x3f, sizeof(dp));
    // dp[i][j][k] == 1 to i non-increasing, sum is j, last is k
    dp[0][0][m] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            int mn = 1e9;
            for (int k = m; k >= 0; k--) {
                chkmin(mn, dp[i-1][j][k]);
                if (j + k <= m) {
                    chkmin(dp[i][j+k][k], mn + abs(p[i] - j - k));
                }
            }
        }
    }
    int res = 1e9;
    for (int k = 0; k <= m; k++)
        chkmin(res, dp[n][m][k]);
    cout << res << "\n";
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

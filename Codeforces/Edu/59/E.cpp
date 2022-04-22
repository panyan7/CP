#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
ll dp[105][105][105][2], a[105], res[105][105];

void umax(ll& a, ll b) {
    a = max(a, b);
}

// check long long
void solve() {
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            umax(a[i], a[j] + a[i-j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        res[i][i] = a[1];
        dp[i][i][1][s[i-1]-'0'] = 0;
    }
    for (int l = 1; l < n; l++) {
        for (int i = 1; i+l <= n; i++) {
            for (int j = i; j+1 <= i+l; j++) {
                umax(res[i][i+l], res[i][j] + res[j+1][i+l]);
            }
            for (char b = '0'; b <= '1'; b++) {
                // dp[i][j][k][b] == maximum points eliminating [i, j], leaving k b
                int total = 0, cnt = 0;
                for (int j = i; j <= i+l; j++)
                    if (s[j-1] == b)
                        total++;
                for (int j = i; j <= i+l; j++) {
                    if (s[j-1] != b)
                        continue;
                    for (int k = 1; k <= total-cnt; k++) {
                        umax(dp[i][i+l][k][b-'0'], res[i][j-1] + dp[j+1][i+l][k-1][b-'0']);
                    }
                    cnt++;
                }
                for (int k = 1; k <= total; k++) {
                    umax(res[i][i+l], dp[i][i+l][k][b-'0'] + a[k]);
                }
            }
            dp[i][i+l][0][0] = res[i][i+l];
            dp[i][i+l][0][1] = res[i][i+l];
        }
    }
    cout << res[1][n] << "\n";
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

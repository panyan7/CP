#include "bits/stdc++.h"
using namespace std;
 
typedef int64_t ll;
 
ll dp[110][110];
ll a[110], c[110];
 
int main() {
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    a[0] = m;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i-1]*2/3;
    }
    for (int i = 1; i <= n; i++)
        dp[i][0] = min(a[0], c[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+min(a[j+1], c[i+1]));
            dp[i+2][j] = max(dp[i+2][j], dp[i][j]+min(a[j], c[i+2]));
            for (int k = 3; k <= 6; k++)
                dp[i+k][0] = max(dp[i+k][0], dp[i][j]+min(a[0], c[i+k]));
        }
    }
    ll res = 0;
    for (int j = 0; j <= n; j++) {
        res = max(res, dp[n][j]);
    }
    cout << res << "\n";
    return 0;
}

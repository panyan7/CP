#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    int M = 1e6;
    vector<int> a(n);
    vector<int> dp(M+1, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = 0;
    for (int i = n-1; i >= 0; i--) {
        dp[a[i]] = 1;
        for (int j = 2 * a[i]; j <= M; j += a[i]) {
            dp[a[i]] = max(dp[a[i]], 1 + dp[j]);
        }
        res = max(res, dp[a[i]]);
    }
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

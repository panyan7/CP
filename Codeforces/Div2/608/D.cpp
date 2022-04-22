#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
int a[5005], b[5005], c[5005], last[5005];
vector<int> def[5005];
int dp[5005][5005];

// check long long
void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        last[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        last[v] = max(last[v], u);
    }
    for (int i = 1; i <= n; i++) {
        def[last[i]].push_back(c[i]);
    }
    for (int i = 1; i <= n; i++) {
        sort(def[i].begin(), def[i].end(), greater<int>());
    }
    memset(dp, ~0x3f, sizeof(dp));
    dp[0][k] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = a[i]; j+b[i] <= 5000; j++) {
            dp[i][j+b[i]] = dp[i-1][j];
            int sm = 0;
            for (int cnt = 1; cnt <= min((int)def[i].size(), j+b[i]); cnt++) {
                sm += def[i][cnt-1];
                dp[i][j+b[i]-cnt] = max(dp[i][j+b[i]-cnt], dp[i][j+b[i]]+sm);
            }
        }
    }
    int res = INT_MIN;
    for (int i = 0; i <= 5000; i++) {
        res = max(res, dp[n][i]);
    }
    cout << (res >= 0 ? res : -1) << "\n";
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

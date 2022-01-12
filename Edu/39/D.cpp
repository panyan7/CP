#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
int dp[505][505], t[505][505], mn[505][505];

// check long long
void solve() {
    cin >> n >> m >> k;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> num_class(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1')
                t[i][cnt++] = j;
        }
        num_class[i] = cnt;
        total += cnt;
    }
    k = min(k, total);
    memset(mn, 0x3f, sizeof(mn));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < num_class[i]; j++) {
            for (int l = 0; l <= j; l++) {
                mn[i][num_class[i]-(j-l+1)] = min(mn[i][num_class[i]-(j-l+1)], t[i][j]-t[i][l]+1);
            }
        }
        for (int j = num_class[i]; j <= k; j++)
            mn[i][j] = 0;
    }
    memset(dp, 0x3f, sizeof(dp));
    // dp[i][j] == first i days, skip j classes
    for (int j = 0; j <= num_class[0]; j++)
        dp[0][j] = mn[0][j];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= j; l++) {
                // skip l classes 
                dp[i][j] = min(dp[i][j], dp[i-1][j-l] + mn[i][l]);
            }
        }
    }
    cout << dp[n-1][k] << "\n";
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

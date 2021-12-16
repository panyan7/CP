#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m;
int c[8][8];

void solve() {
    cin >> n >> m;
    vector<string> a (n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n > 3) {
        cout << -1 << "\n";
        return;
    }
    int b = 1 << n;
    vector<vector<int>> dp (m, vector<int> (b, INT_MAX));
    for (int i = 0; i < b; ++i) {
        dp[0][i] = 0;
        for (int j = 0; j < n; ++j)
            dp[0][i] += (a[j][0]-'0') ^ (i >> j & 1);
        for (int j = 0; j < 8; ++j) {
            vector<int> a;
            int tmp = i ^ j;
            for (int k = 0; k < n; ++k)
                a.push_back(tmp >> k & 1);
            c[i][j] = 1;
            for (int k = 0; k < n-1; ++k)
                c[i][j] &= (a[k] ^ a[k+1]);
        }
    }
    for (int k = 1; k < m; ++k) {
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < b; ++j) {
                if (c[i][j]) {
                    dp[k][i] = min(dp[k][i], dp[k-1][j]);
                }
            }
            for (int j = 0; j < n; ++j) {
                dp[k][i] += (a[j][k]-'0') ^ (i >> j & 1);
            }           
        }
    }
    cout << *min_element(all(dp[m-1])) << "\n";
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

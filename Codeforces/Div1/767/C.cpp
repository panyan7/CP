#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<vector<ll>> grid(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    vector<vector<bool>> choose(n, vector<bool>(n, 0));
    for (int i = 0; i < n/2; i += 4) {
        for (int j = i; j < n-i-1; j += 2) {
            choose[i][j] = 1;
            choose[j][i] = 1;
            choose[n-i-2][j] = 1;
            choose[j][n-i-2] = 1;
        }
        for (int j = i+1; j < n-i-1; j += 2) {
            choose[i+1][j] = 1;
            choose[j][i+1] = 1;
            choose[n-i-3][j] = 1;
            choose[j][n-i-3] = 1;
        }
    }
    for (int i = 0; i < n/2; i += 4) {
        for (int j = i; j < n-i-1; j += 2) {
            choose[i][j+1] = 1;
            choose[j][i+1] = 1;
            choose[n-i-2][j+1] = 1;
            choose[j][n-i-2+1] = 1;
        }
        for (int j = i+1; j < n-i-1; j += 2) {
            choose[i+1][j+1] = 1;
            choose[j][i+1+1] = 1;
            choose[n-i-3][j+1] = 1;
            choose[j][n-i-3+1] = 1;
        }
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (choose[i][j])
                res ^= grid[i][j];
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

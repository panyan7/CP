#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    ll res = 0;
    int mn = max(n, m) + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll sum = board[i][j];
            for (int k = 1; k < mn; k++) {
                if (i+k >= n || j+k >= m)
                    break;
                sum += board[i+k][j+k];
            }
            for (int k = 1; k < mn; k++) {
                if (i-k < 0 || j-k < 0)
                    break;
                sum += board[i-k][j-k];
            }
            for (int k = 1; k < mn; k++) {
                if (i+k >= n || j-k < 0)
                    break;
                sum += board[i+k][j-k];
            }
            for (int k = 1; k < mn; k++) {
                if (i-k < 0 || j+k >= m)
                    break;
                sum += board[i-k][j+k];
            }
            res = max(res, sum);
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

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n >> m;
    vector<string> board(n);
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++)
        cin >> board[i];
    vector<int> best(4, INT_MIN);
    vector<pii> p(4);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'W')
                continue;
            if (i+j > best[0]) {
                best[0] = i+j;
                p[0] = {i,j};
            }
            if (-i-j > best[1]) {
                best[1] = -i-j;
                p[1] = {i,j};
            }
            if (i-j > best[2]) {
                best[2] = i-j;
                p[2] = {i,j};
            }
            if (-i+j > best[3]) {
                best[3] = -i+j;
                p[3] = {i,j};
            }
        }
    }
    int res_val = INT_MAX;
    pii res = {0,0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int d = INT_MIN;
            for (int k = 0; k < 4; k++) {
                d = max(d, abs(i-p[k].first) + abs(j-p[k].second));
            }
            if (d < res_val) {
                res_val = d;
                res = {i,j};
            }
        }
    }
    cout << res.first+1 << " " << res.second+1 << "\n";
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

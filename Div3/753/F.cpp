#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<bool>> vis;
vector<string> board;
map<pii,int> cur;
int step[2005][2005];

pii dfs(int x, int y, int cnt) {
    if (x < 0 || x >= n || y < 0 || y >= m)
        return {0, 1};
    if (cur.find({x,y}) != cur.end())
        return {cur[{x,y}], cnt-cur[{x,y}]};
    if (vis[x][y])
        return {0, step[x][y]+1};
    vis[x][y] = true;
    cur[{x,y}] = cnt;
    pii res;
    if (board[x][y] == 'U') {
        res = dfs(x-1, y, cnt+1);
    } else if (board[x][y] == 'D') {
        res = dfs(x+1, y, cnt+1);
    } else if (board[x][y] == 'L') {
        res = dfs(x, y-1, cnt+1);
    } else {
        res = dfs(x, y+1, cnt+1);
    }
    cur.erase({x,y});
    if (res.first && cnt >= res.first) {
        step[x][y] = res.second;
    } else {
        step[x][y] = res.second;
    }
    if (res.first && cnt > res.first)
        return res;
    else
        return {0, res.second+1};
};

// check long long
void solve() {
    cin >> n >> m;
    board.resize(n);
    for (auto& s : board)
        cin >> s;
    vis.assign(n, vector<bool>(m, 0));
    cur.clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            step[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                dfs(i, j, 1);
            }
        }
    }
    int bd = 0, bx = 0, by = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //cout << step[i][j] << " ";
            if (step[i][j] > bd) {
                bd = step[i][j];
                bx = i;
                by = j;
            }
        }
        //cout << "\n";
    }
    cout << bx+1 << " " << by+1 << " " << bd << "\n";
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

#include <bits/stdc++.h>
using namespace std;
 
bool vis[10][10][105][105][3][3];
char grid[10][10];
using arr = array<int,6>;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }
    int k; cin >> k;
    string s; cin >> s;
    if (k > (int)s.size() - 1) {
        cout << "NO\n";
        return 0;
    }
    queue<arr> q;
    auto add = [&](int x, int y, int h, int l, int dx, int dy) {
        if (!vis[x][y][h][l][dx+1][dy+1]) {
            vis[x][y][h][l][dx+1][dy+1] = true;
            q.push({x, y, h, l, dx, dy});
        }
    };
    auto add_neighbors = [&](int x, int y, int h, int l, int dx, int dy) {
        if (grid[x][y] != s[l])
            return;
        if (l+1 >= (int)s.size())
            return;
        for (int dx1 = -1; dx1 <= 1; dx1++) {
            for (int dy1 = -1; dy1 <= 1; dy1++) {
                if (dx1 == 0 && dy1 == 0)
                    continue;
                if (x+dx1 < 0 || x+dx1 >= r || y+dy1 < 0 || y+dy1 >= c)
                    continue;
                if (s[l+1] == grid[x+dx1][y+dy1]) {
                    add(x+dx1, y+dy1, h+((dx1 == dx && dy1 == dy) ? 0 : 1), l+1, dx1, dy1);
                }
            }
        }
    };
    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            if (s[0] == grid[x][y]) {
                add(x, y, 0, 0, 0, 0);
                if (s.size() == 1 && k == 0) {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }
    while (!q.empty()) {
        auto [x, y, h, l, dx, dy] = q.front();
        q.pop();
        if (l == (int)s.size())
            continue;
        add_neighbors(x, y, h, l, dx, dy);
    }
    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (vis[x][y][k+1][(int)s.size()-1][dx+1][dy+1]) {
                        cout << "YES\n";
                        return 0;
                    }
                }
            }
            
        }
    }
    cout << "NO\n";
    return 0;
}

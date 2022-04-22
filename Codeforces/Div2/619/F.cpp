#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
int color[1005][1005], dist[42][1005][1005];
bool vis[1005][1005];

// check long long
void solve() {
    cin >> n >> m >> k;
    vector<vector<pii>> color_list(k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> color[i][j];
            color[i][j]--;
            color_list[color[i][j]].push_back({i, j});
        }
    }
    vector<vector<pii>> best_point(k, vector<pii>(k, {-1, -1}));
    memset(dist, 0x3f, sizeof(dist));
    for (int c = 0; c < k; c++) {
        queue<pii> q;
        memset(vis, 0, sizeof(vis));
        for (auto v : color_list[c]) {
            int vx = v.first, vy = v.second;
            dist[c][vx][vy] = 0;
            vis[vx][vy] = 1;
            q.push(v);
        }
        vector<bool> vis_color(k, 0);
        vis_color[c] = 1;
        while (!q.empty()) {
            pii v = q.front();
            int vx = v.first, vy = v.second;
            q.pop();
            vector<pii> nbor = {{vx-1, vy}, {vx+1, vy}, {vx, vy-1}, {vx, vy+1}};
            if (!vis_color[color[vx][vy]]) {
                for (pii u : color_list[color[vx][vy]]) {
                    nbor.push_back(u);
                }
                vis_color[color[vx][vy]] = 1;
            }
            for (pii u : nbor) {
                int ux = u.first, uy = u.second;
                if (ux < 0 || uy < 0 || ux >= n || uy >= m)
                    continue;
                if (!vis[ux][uy]) {
                    vis[ux][uy] = true;
                    q.push(u);
                    dist[c][ux][uy] = dist[c][vx][vy] + 1;
                }
            }
        }
    }
    int qr;
    cin >> qr;
    for (int i = 0; i < qr; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        int res = abs(x1-x2) + abs(y1-y2);
        for (int c = 0; c < k; c++)
            res = min(res, dist[c][x1][y1] + dist[c][x2][y2] + 1);
        cout << res << "\n";
    }
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

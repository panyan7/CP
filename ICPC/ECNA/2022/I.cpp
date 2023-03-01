// Undecidable
#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<vector<pair<int, int>>> e;
int dist[200][200];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s >> t;
    s--; t--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            dist[i][j] = 1 << 20;
        }
    }
    e.resize(n);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int u, v;
        int w;
        cin >> u >> v >> w;
        u--; v--;
        ans += 2 * w;
        e[u].push_back({v, w}); e[v].push_back({u, w});
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    // for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cout << dist[i][j] << ' ';

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int tot = dist[s][t];
    // int ans = 0;
    // cout << tot << '\n';
    for (int i = 0; i < n; i++) {
        for (auto [v, w] : e[i]) {
            if (w + dist[s][v] + dist[i][t] == tot || w + dist[s][i] + dist[v][t] == tot) ans -= w;
        }
    }
    cout << ans / 2 << '\n';
}


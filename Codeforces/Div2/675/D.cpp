#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
const int INF = 1e15; // Large value, INT_MAX may cause overflow
vector<vector<pii>> adj;
vector<int> dist, p;

void dijkstra(vector<int>& source) {
    dist.assign(m+2, -1);
    p.assign(m+2, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int s : source) {
        pq.push({0, s});
        dist[s] = 0;
    }
    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if (dist[v] != d) // Skip impossible paths
            continue;
        for (auto e : adj[v]) {
            int u = e.first, w = e.second;
            if (dist[u] == -1 || dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                p[u] = v;
                pq.push({dist[u], u});
            }
        }
    }
}

// check long long
void solve() {
    cin >> n >> m;
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    adj.assign(m+2, {});
    vector<pii> loc(m);
    for (int i = 0; i < m; i++) {
        cin >> loc[i].first >> loc[i].second;
    }
    loc.push_back({sx, sy});
    loc.push_back({tx, ty});
    vector<int> id(m+1);
    for (int i = 0; i < m+1; i++)
        id[i] = i;

    sort(id.begin(), id.end(), [&](int a, int b) { return loc[a].first == loc[b].first ? loc[a].second < loc[b].second : loc[a].first < loc[b].first; });

    for (int i = 0; i+1 < m+1; i++) {
        pii l1 = loc[id[i]], l2 = loc[id[i+1]];
        //int d = min(abs(l1.first - l2.first), abs(l1.second - l2.second));
        int d = abs(l1.first - l2.first);

        if (id[i+1] < m)
            adj[id[i]].push_back({id[i+1], d});

        if (id[i] < m)
            adj[id[i+1]].push_back({id[i], d});
    }

    sort(id.begin(), id.end(), [&](int a, int b) { return loc[a].second == loc[b].second ? loc[a].first < loc[b].first : loc[a].second < loc[b].second; });

    for (int i = 0; i+1 < m+1; i++) {
        pii l1 = loc[id[i]], l2 = loc[id[i+1]];
        int d = abs(l1.second - l2.second);

        if (id[i+1] < m)
            adj[id[i]].push_back({id[i+1], d});

        if (id[i] < m)
            adj[id[i+1]].push_back({id[i], d});
    }

    for (int i = 0; i < m; i++) {
        int raw_d = abs(loc[i].first - tx) + abs(loc[i].second - ty);
        adj[i].push_back({m+1, raw_d});
    }

    adj[m].push_back({m+1, abs(sx-tx) + abs(sy-ty)});

    vector<int> source = {m};
    dijkstra(source);
    cout << dist[m+1] << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

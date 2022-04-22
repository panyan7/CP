#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m;
vector<vector<array<int,2>>> adj;

class cmp {
public:
    bool operator () (const array<int,4> a, const array<int,4> b) {
        return (a[0]-a[1]+a[2]) < (b[0]-b[1]+b[2]);
    }
};

void solve() {
    cin >> n >> m;
    adj.assign(n, vector<array<int,2>> (0));
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[v-1].push_back({u-1, w});
        adj[u-1].push_back({v-1, w});
    }
    typedef priority_queue<array<int,4>, vector<array<int,4>>, cmp> pq_t;
    pq_t pq;
    pq.push({0, 0, 0, 0});
    vector<array<int,3>> d (n, {(int)1e15, 0, 0});
    d[0] = {0, 0, 0};
    while (!pq.empty()) {
        array<int,4> vn = pq.top();
        int v = vn[3];
        pq.pop();

        for (auto e : adj[v]) {
            int u = e[0], w = e[1];
            if (d[v][0]-max(d[v][1], w)+min(d[v][2], w)+w < d[u][0]) {
                d[u] = {d[v][0]+w, max(d[v][1],w), min(d[v][2],w)};
                pq.push({d[u][0],d[u][1],d[u][2],u});
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        cout << d[i][0]-d[i][1]+d[i][2] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

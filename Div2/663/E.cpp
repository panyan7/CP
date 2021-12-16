#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t, n, m, k;

vector<int> dist;
vector<vector<int>> adj, lvl;
int res;

bool dfs(int v, int p) {
    if (p == -1) dist[v] = 1;
    else dist[v] = dist[p] + 1;
    if (dist[v] >= (n+1)/2) {
        cout << "PATH\n";
        cout << dist[v] << "\n";
        cout << v+1 << " ";
        return true;
    }
    lvl[dist[v]].push_back(v+1);
    res += (int(lvl[dist[v]].size()) % 2 == 0);
    for (int u : adj[v]) {
        if (dist[u] < 0) {
            if (dfs(u, v)) {
                cout << v+1 << (p == -1 ? "\n" : " ");
                return true;
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    adj.assign(n, vector<int> ());
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    dist.assign(n, -1);
    lvl.assign(n+1, vector<int> ());
    res = 0;
    if (dfs(0, -1)) return;
    cout << "PAIRING\n";
    cout << res << "\n";
    for (auto row : lvl) {
        for (int i = 0; i+1 < row.size(); i+=2) {
            cout << row[i] << " " << row[i+1] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

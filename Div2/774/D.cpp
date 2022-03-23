#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n == 2) {
        cout << "2 2\n1 1\n";
        return;
    }
    // make adj
    vector<int> side(n, -1);
    bool is_bipartite = true;
    queue<int> q;
    for (int st = 0; st < n; ++st) {
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }
    assert(is_bipartite);
    int cnt[2] = {0, 0}, w[2] = {0, 0};
    vector<vector<int>> res(2, vector<int>(n, 1));
    for (int s = 0; s < 2; s++) {
        for (int i = 0; i < n; i++) {
            if (side[i] == s) {
                cnt[s]++;
                res[s][i] = adj[i].size();
            }
            w[s] += res[s][i];
        }
    }
    for (int s = 0; s < 2; s++) {
        q = queue<int>();
        vector<bool> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1 && side[i] != s) {
                q.push(i);
                vis[i] = true;
            }
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            int cnt = 0;
            for (int u : adj[v]) {
                if (!vis[u] && side[u] == s) {
                    cnt++;
                }
            }
            if (cnt == 1) {
                for (int u : adj[v]) {
                    if (!vis[u] && side[u] == s) {
                        vis[u] = true;
                        w[s] -= res[s][u] + res[s][v];
                        res[s][u] = 1;
                        //assert(adj[v].size() <= 2);
                        res[s][v] = adj[v].size();
                        w[s] += res[s][u] + res[s][v];
                        for (int w : adj[u]) {
                            if (!vis[w]) {
                                vis[w] = true;
                                q.push(w);
                            }
                        }
                    }
                }
            }
        }
    }
    int s = 0;
    if (cnt[0] == cnt[1]) {
        s = (w[0] < w[1] ? 0 : 1);
    } else {
        s = (cnt[0] > cnt[1] ? 0 : 1);
    }
    cout << cnt[s] << " " << w[s] << "\n";
    for (int i = 0; i < n; i++)
        cout << res[s][i] << " ";
    cout << "\n";
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

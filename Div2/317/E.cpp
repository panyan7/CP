#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
 
int tt = 1, n, m, k;
vector<vector<int>> a;
vector<vector<array<int,3>>> adj;
vector<array<int,3>> parent;
int cycle_start, cycle_end;
vector<bool> vis, anc, vis2;
vector<bool> ok;
string res;
vector<int> cycle;
 
void dfs1(int v) {
    //cout << v << "!";
    vis[v] = true;
    for (auto [u, i, j] : adj[v]) {
        if (!vis[u]) {
            //cout << v << "-" << u << " " << i << " " << j << "\n";
            res[i] = '0' + j;
            dfs1(u);
        }
    }
}
 
bool dfs_cycle(int v, int pe) { // passing vertex and its parent vertex
    //cout << v << " " << pe << "\n";
    vis2[v] = true;
    for (auto [u, i, j] : adj[v]) {
        if (i == pe)
            continue; // skipping edge to parent vertex
        if (vis2[u]) {
            cycle_end = v;
            cycle_start = u;
            parent[u] = {-1, i, j};
            return true;
        }
        parent[u] = {v, i, j};
        if (dfs_cycle(u, i))
            return true;
    }
    return false;
}
 
bool find_cycle(int v) {
    //vis.assign(n, false);
    cycle_start = -1;

    if (!dfs_cycle(v, parent[v][1]))
        return false;
 
    if (cycle_start == -1) {
        return false;
    } else {
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v][0])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        for (int l = 0; l < cycle.size(); l++) {
            //cout << cycle[l] << " ";
            auto [u, i, j] = parent[cycle[l]];
            res[i] = '0' + j;
        }
        return true;
    }
}
 
// check long long
void solve() {
    cin >> n >> m;
    ok.assign(n+1, 0);
    //vector<array<int,2>> has(n+1, {0, 0});
    res = string(m, '?');
    vector<vector<vector<int>>> has(m, vector<vector<int>>(2));
    adj.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            int t = 1;
            if (x < 0) {
                x = -x;
                t = 0;
            }
            x--;
            has[x][t].push_back(i);
        }
    }
    for (int i = 0; i < m; i++) {
        bool can = false;
        for (int j = 0; j < 2; j++) {
            if (has[i][j].empty()) {
                can = true;
                res[i] = '0' + (j ^ 1);
                for (int v : has[i][j ^ 1])
                    ok[v] = true;
                break;
            }
        }
        if (!can) {
            for (int j = 0; j < 2; j++)
                adj[has[i][j][0]].push_back({has[i][j^1][0], i, j^1});
        }
    }
 
    vis.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (ok[i] && !vis[i]) {
            // mark everything connected to some ok clause 
            dfs1(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (vis[i])
            ok[i] = 1;
    }
    bool all_ok = true;
    for (int i = 0; i < n; i++)
        if (!vis[i])
            all_ok = false;
    if (all_ok) {
        cout << "YES\n";
        for (int i = 0; i < m; i++) {
            if (res[i] == '?')
                res[i] = '0';
        }
        cout << res << "\n";
        return;
    }
    vis2 = ok;
    parent.assign(n, {-1, -1, -1});
    for (int i = 0; i < n; i++) {
        if (!vis[i] && !vis2[i]) {
            cycle.clear();
            bool can = find_cycle(i);
            if (!can) {
                cout << "NO\n";
                return;
            }
            for (int i = 0; i < cycle.size(); i++) {
                dfs1(cycle[i]);
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < m; i++) {
        if (res[i] == '?')
            res[i] = '0';
    }
    cout << res << "\n";
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


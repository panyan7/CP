#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
 
int tt = 1, n, m, k;
 
vector<int> parent;
vector<int> sz;
set<int> vert;
unordered_map<int, unordered_set<int>> adj;
vector<array<int,3>> edges;
vector<int> res;
 
int find_set(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find_set(parent[v]); // optimizes depth 
}
bool union_sets(int v, int u) {
    v = find_set(v), u = find_set(u);
    if (v == u)
        return false;
    if (sz[v] < sz[u])
        swap(v, u); // optimizes depth
    parent[u] = v;
    sz[v] += sz[u];
    return true;
}

bool solve2(int r) {
    vector<pii> imp;
    parent.assign(n, 0);
    sz.assign(n, 1);
    for (int v = 0; v < n; ++v)
        parent[v] = v;
    for (int i = 0; i < m; i++) {
        int u = edges[i][0], v = edges[i][1], s = edges[i][2];
        if (s == r) {
            union_sets(v, u);
        } else {
            imp.push_back({v, u});
        }
    }
    adj.clear();
    for (pii p : imp) {
        int u = p.first, v = p.second;
        v = find_set(v), u = find_set(u);
        if (v == u) {
            return false;
        }
        adj[v].insert(u);
        adj[u].insert(v);
    }
    bool can = true;
    vert.clear();
    for (int i = 0; i < n; i++)
        vert.insert(find_set(i));
    vector<int> side(n, -1);
    bool is_bipartite = true;
    queue<int> q;
    unordered_set<int> win_side;
    for (int st : vert) {
        array<int,2> cnt = {0,0};
        vector<int> vs[2];
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            vs[0].push_back(st);
            cnt[0] += sz[st];
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        vs[side[u]].push_back(u);
                        cnt[side[u]] += sz[u];
                        q.push(u);
                    } else {
                        is_bipartite &= (side[u] != side[v]);
                    }
                }
            }
        }
        if (cnt[0] < cnt[1]) {
            for (int v : vs[0])
                win_side.insert(v);
        } else {
            for (int v : vs[1])
                win_side.insert(v);
        }
    }
    if (is_bipartite) {
        res.clear();
        for (int i = 0; i < n; i++) {
            if (win_side.find(find_set(i)) != win_side.end()) {
                res.push_back(i+1);
            }
        }
    }
    return is_bipartite;
}
 
// check long long
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; string c;
        cin >> u >> v >> c;
        u--, v--;
        if (c == "R")
            edges.push_back({u, v, 1});
        else
            edges.push_back({u, v, -1});
    }
    vector<int> res1, res2;
    bool ok = false;
    int best = 1e9;
    if (solve2(1)) {
        res1 = res;
        best = min(best, (int)res1.size());
        ok = true;
    }
    if (solve2(-1)) {
        res2 = res;
        best = min(best, (int)res2.size());
        ok = true;
    }
    if (!ok)
        cout << "-1\n";
    else {
        if (res1.size() == best) {
            cout << res1.size() << "\n";
            for (int i = 0; i < res1.size(); i++)
                cout << res1[i] << " ";
            cout << "\n";
        } else {
            cout << res2.size() << "\n";
            for (int i = 0; i < res2.size(); i++)
                cout << res2[i] << " ";
            cout << "\n";
        }
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


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

vector<int> parent;
vector<int> sz;
vector<pii> imp;
set<int> vert;
unordered_map<int, unordered_set<int>> adj;

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

// check long long
void solve() {
    cin >> n >> m;
    parent.assign(n, 0);
    sz.assign(n, 1);
    imp.resize(0);
    for (int v = 0; v < n; ++v)
        parent[v] = v;
    for (int i = 0; i < m; i++) {
        int u, v; string s;
        cin >> v >> u >> s;
        v--, u--;
        if (s == "crewmate") {
            union_sets(v, u);
        } else{
            imp.push_back({v, u});
        }
    }
    bool can = true;
    vert.clear();
    adj.clear();
    for (int i = 0; i < n; i++)
        vert.insert(find_set(i));
    for (auto p : imp) {
        int v = find_set(p.first), u = find_set(p.second);
        if (v == u) {
            cout << "-1\n";
            return;
        }
        adj[v].insert(u);
        adj[u].insert(v);
    }
    vector<int> side(n, -1);
    bool is_bipartite = true;
    queue<int> q;
    int res = 0;
    for (int st : vert) {
        array<int,2> cnt = {0,0};
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            cnt[0] += sz[st];
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        cnt[side[u]] += sz[u];
                        q.push(u);
                    } else {
                        is_bipartite &= (side[u] != side[v]);
                    }
                }
            }
        }
        res += max(cnt[0], cnt[1]);
    }
    //cout << (is_bipartite ? "YES" : "NO") << endl; 
    if (!is_bipartite) {
        cout << "-1\n";
        return;
    }
    cout << res << "\n";
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

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n >> m >> k;
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    vector<string> res;
    vector<int> vis(n, 0);
    vector<int> d(n, 1e9);
    vector<vector<pii>> parent(n);
    queue<int> q;
    vis[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (pii p : adj[v]) {
            int u = p.first;
            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                parent[u].push_back(p);
            } else {
                if (d[u] == d[v] + 1) {
                    parent[u].push_back(p);
                }
            }
        }
    }
    res.push_back(string(m, '0'));
    for (int i = 1; i < n; i++) {
        if (res.size() == k || parent[i].size() == 1) {
            for (string& s : res) {
                s[parent[i][0].second] = '1';
            }
        } else {
            vector<string> temp;
            for (string s : res) {
                if (temp.size() >= k)
                    break;
                for (pii p : parent[i]) {
                    if (temp.size() >= k)
                        break;
                    string s1 = s;
                    s1[p.second] = '1';
                    temp.push_back(s1);
                }
            }
            res = temp;

        }
    }
    cout << res.size() << "\n";
    for (string s : res)
        cout << s << "\n";
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

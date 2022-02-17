#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
ll cnt[3005][3005];
bool adjm[3005][3005];
vector<vector<int>> adj, adjr;

// check long long
void solve() {
    cin >> n >> m;
    adj.resize(n);
    adjr.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adjm[u][v] = true;
        adj[u].push_back(v);
        adjr[v].push_back(u);
    }
    ll res = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < adjr[k].size(); i++) {
            for (int j = i+1; j < adjr[k].size(); j++) {
                cnt[adjr[k][i]][adjr[k][j]]++;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < adj[k].size(); i++) {
            for (int j = i+1; j < adj[k].size(); j++) {
                res += cnt[adj[k][i]][adj[k][j]] + cnt[adj[k][j]][adj[k][i]];
                if (adjm[adj[k][i]][k] && adjm[adj[k][j]][k])
                    res--;
            }
        }
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

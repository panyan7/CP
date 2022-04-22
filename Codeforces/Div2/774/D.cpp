#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
ll dp[200005][2][2];
ll w[200005];
bool vis[200005];
vector<vector<int>> adj;

void dfs(int v) {
    vis[v] = true;
    dp[v][1][0] = 1;
    dp[v][1][1] = adj[v].size();
    dp[v][0][1] = 0;
    dp[v][0][1] = 1;
    for (int u : adj[v]) {
        if (!vis[u]) {
            dfs(u);
            dp[v][1][0] += dp[u][0][0];
            dp[v][1][1] += dp[u][0][1];
            if (dp[u][0][0] > dp[u][1][0]) {
                dp[v][0][0] += dp[u][0][0];
                dp[v][0][1] += dp[u][0][1];
            } else if (dp[u][0][0] < dp[u][1][0]){
                dp[v][0][0] += dp[u][1][0];
                dp[v][0][1] += dp[u][1][1];
            } else {
                if (dp[u][0][1] < dp[u][1][1]) {
                    dp[v][0][0] += dp[u][0][0];
                    dp[v][0][1] += dp[u][0][1];
                } else {
                    dp[v][0][0] += dp[u][1][0];
                    dp[v][0][1] += dp[u][1][1];
                }
            }
        }
    }
}

void dfs2(int v, bool f=false) {
    if (f) {
        w[v] = 1;
        f = false;
    } else {
        if (dp[v][1][0] > dp[v][0][0]) {
            f = true;
            w[v] = adj[v].size();
        } else if (dp[v][0][0] == dp[v][1][0] && dp[v][1][1] < dp[v][0][1]) {
            f = true;
            w[v] = adj[v].size();
        } else {
            w[v] = 1;
        }
    }
    for (int u : adj[v]) {
        if (w[u] == 0) {
            dfs2(u, f);
        }
    }
}

void solve() {
    cin >> n;
    adj.resize(n);
    memset(dp, 0, sizeof(dp));
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
    dfs(0);
    dfs2(0);
    ll res = 0;
    for (int i = 0; i < n; i++)
        res += w[i];
    cout << max(dp[0][0][0], dp[0][1][0]) << " " << res << "\n";
    for (int i = 0; i < n; i++)
        cout << w[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

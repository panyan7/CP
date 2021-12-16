#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    adj.assign(20, vector<int> ());
    visited.assign(20, false);
    vector<int> mat (20, 0);
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            mat[a[i]-'a'] |= 1 << (b[i]-'a');
            adj[a[i]-'a'].push_back(b[i]-'a');
            adj[b[i]-'a'].push_back(a[i]-'a');
        }
    }
    int cnt = 0;
    for (int v = 0; v < 20; ++v) {
        if (!visited[v]) {
            dfs(v);
            ++cnt;
        }
    }
    int ans = 0, k = (1<<20);
    vector<bool> dp (k, false);
    dp[0] = true;
    for (int i = 0; i < k; ++i) {
        if (dp[i]) {
            ans = max(ans, __builtin_popcount((unsigned int)i));
            for (int v = 0; v < 20; ++v) {
                if ((~i >> v & 1) && (mat[v] & i) == 0)
                    dp[i | 1<<v] = true;
            }
        }
    }
    cout << 40-cnt-ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

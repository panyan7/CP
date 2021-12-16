#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m;
vector<bool> visited;
vector<vector<int>> adj;
void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

void solve() {
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    adj.assign(20, vector<int> ());
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            cout << -1 << "\n";
            return;
        } else if (a[i] < b[i]) {
            adj[a[i]-'a'].push_back(b[i]-'a');
            adj[b[i]-'a'].push_back(a[i]-'a');
        }
    }
    visited.assign(20, false);
    int res = 0;
    for (int v = 0; v < 20; ++v) {
        if (!visited[v]) {
            ++res;
            dfs(v);
        }
    }
    cout << 20-res << "\n";
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

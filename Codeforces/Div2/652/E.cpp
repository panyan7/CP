#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;
vector<vector<pii>> adj;

void dfs(int v) {
    
}

void solve() {
    cin >> n >> m;
    vector<int> a(n), cnt(n, 0);
    for (auto& x : a)
        cin >> x;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
        cnt[x]++; cnt[y]++;
    }
    vector<bool> vis(m, 0);
    queue<int> q;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (cnt[i] <= a[i])
            q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto [u, j] : adj[v]) {
                if (vis[j])
                    continue;
                vis[j] = true;
                res.push_back(j);
                cnt[u]--;
                if (cnt[u] == a[u])
                    q.push(u);
            }
        }
    }
    reverse(res.begin(), res.end());
    if (res.size() < m) {
        cout << "DEAD\n";
        return;
    }
    cout << "ALIVE\n";
    for (int i = 0; i < m; i++) {
        cout << res[i]+1 << " \n"[i+1==m];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

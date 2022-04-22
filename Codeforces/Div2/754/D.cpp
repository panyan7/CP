#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> color;

void dfs(int v) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u]) {
            color[u] = color[v] ^ 1;
            dfs(u);
        }
    }
}

// check long long
void solve() {
    cin >> n;
    adj.assign(n, vector<int>());
    vis.assign(n, 0);
    color.assign(n, -1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    color[0] = 0;
    dfs(0);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0)
            cnt++;
    }
    if (cnt <= n/2) {
        for (int i = 0; i < n; i++) {
            color[i] = color[i] ^ 1;
        }
        cnt = n - cnt;
    }
    cnt = n - cnt;
    // cout << cnt << "\n";
    // cnt is less than n/2, number of colors 1
    vector<int> idx(n+1);
    for (int i = 0; i < 20; i++) {
        if ((1 << i) > cnt)
            break;
        int b = cnt & (1 << i);
        if (b) {
            for (int j = (1 << i); j <= min((1 << (i+1))-1, n); j++) {
                assert(1 <= j && j <= n);
                idx[j] = 1;
            }
        }
    }
    vector<int> res(n);
    int i0 = 1, i1 = 1;
    while (i0 <= n && idx[i0])
        i0++;
    while (i1 <= n && !idx[i1])
        i1++;
    for (int i = 0; i < n; i++) {
        if (!color[i]) {
            assert(1 <= i0 && i0 <= n);
            res[i] = i0;
            i0++;
            while (i0 <= n && idx[i0])
                i0++;
        } else {
            assert(1 <= i1 && i1 <= n);
            res[i] = i1;
            i1++;
            while (i1 <= n && !idx[i1])
                i1++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " \n"[i+1==n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

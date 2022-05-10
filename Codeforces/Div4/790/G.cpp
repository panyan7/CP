#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj;
vector<bool> vis;
vector<pii> num;
string s;
int res = 0;

void dfs(int v) {
    vis[v] = true;
    if (s[v] == 'B')
        num[v].first += 1;
    else
        num[v].second += 1;
    for (int u : adj[v]) {
        if (!vis[u]) {
            dfs(u);
            num[v].first += num[u].first;
            num[v].second += num[u].second;
        }
    }
    if (num[v].first == num[v].second)
        res++;
}

void solve() {
    cin >> n;
    adj.clear();
    adj.resize(n);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        adj[x].push_back(i);
    }
    cin >> s;
    vis.assign(n, 0);
    num.assign(n, {0,0});
    res = 0;
    dfs(0);
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

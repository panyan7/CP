#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int s, t;
    cin >> s >> t;
    s--, t--;
    m = 3 * 1e5;
    vector<vector<int>> adj(m+n+1);
    vector<bool> has(m+1, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] == 1)
            continue;
        if (has[a[i]] && i != s && i != t)
            continue;
        has[a[i]] = true;
        adj[i].push_back(n + a[i]);
        adj[n + a[i]].push_back(i);
        for (int j = 2; j <= sqrt(a[i]); j++) {
            if (a[i] % j != 0)
                continue;
            adj[i].push_back(n + j);
            adj[n + j].push_back(i);
            if (j * j != a[i]) {
                adj[i].push_back(n + a[i] / j);
                adj[n + a[i] / j].push_back(i);
            }
        }
    }
    vector<int> dist(m+n+1, 1e9);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (dist[u] >= 1e9)
                q.push(u);
            dist[u] = min(dist[u], dist[v] + 1);
        }
    }
    if (dist[t] >= 1e9) {
        cout << "-1\n";
        return;
    }
    vector<int> res;
    res.push_back(t);
    int v = t;
    while (v != s) {
        for (int u : adj[v]) {
            if (dist[u] < dist[v]) {
                res.push_back(u);
                v = u;
                break;
            }
        }
    }
    reverse(res.begin(), res.end());
    cout << (res.size() + 1) / 2 << "\n";
    for (int v : res) {
        if (v < n)
            cout << v+1 << " ";
    }
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

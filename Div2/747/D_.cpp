#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n >> m;
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        string c;
        cin >> u >> v >> c;
        u--, v--;
        if (c == "imposter") {
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 1});
        } else {
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 0});
        }
    }
    vector<int> side(n, -1);
    queue<int> q;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (side[i] == -1) {
            q.push(i);
            side[i] = 0;
            array<int,2> cnt = {0, 0};
            cnt[0]++;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (auto [u, j] : adj[v]) {
                    if (side[u] == -1) {
                        q.push(u);
                        side[u] = side[v] ^ j;
                        cnt[side[u]]++;
                    } else {
                        if (j != (side[u] ^ side[v])) {
                            cout << "-1\n";
                            return;
                        }
                    }
                }
            }
            res += max(cnt[0], cnt[1]);
        }
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

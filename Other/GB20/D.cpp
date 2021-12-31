#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

int t, n;
vector<pair<ll, ll>> G;

void solve() {
    sort(G.begin(), G.end());
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        res += G[i].first;
    }
    int id = n;
    for (int i = 1; i <= n-1; ++i) {
        if (i == n-1) {
            cout << res << "\n";
            return;
        }
        cout << res << " ";
        while (G[id].second <= 1) {
            --id;
        }
        res += G[id].first;
        --G[id].second;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        G.assign(n+1, {0,0});
        for (int i = 1; i <= n; ++i)
            cin >> G[i].first;
        for (int i = 1; i <= n-1; ++i) {
            int u, v;
            cin >> u >> v;
            ++G[u].second;
            ++G[v].second;
        }
        solve();
    }
}

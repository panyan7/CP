#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
bool vis1[20000005];
bool vis[1000005];

void solve() {
    cin >> n >> m;
    ll res = 1;
    vector<ll> mul(20);
    ll c = 0;
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis1[i * j]) {
                vis1[i * j] = true;
                c++;
            }
        }
        mul[i] = c;
    }
    for (ll i = 2; i <= n; i++) {
        if (vis[i])
            continue;
        ll p = 0;
        for (ll j = i; j <= n; j *= i) {
            vis[j] = true;
            p++;
            //res += m - (p-1)*m/p;
            //res += m/p;
        }
        res += mul[p];
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

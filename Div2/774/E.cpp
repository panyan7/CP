#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
bool vis[1000005];

void solve() {
    cin >> n >> m;
    ll res = 1;
    for (ll i = 2; i <= n; i++) {
        if (vis[i])
            continue;
        ll p = 0;
        for (ll j = i; j <= n; j *= i) {
            vis[j] = true;
            p++;
            res += m - (p-1)*m/p;
            //res += m/p;
        }
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

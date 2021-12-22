#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    ll cost = 0;
    if (e > f) {
        cost += e * min(a, d);
        d -= min(a, d);
        cost += f * min(min(b, c), d);
    } else {
        cost += f * min(min(b, c), d);
        d -= min(min(b, c), d);
        cost += e * min(a, d);
    }
    cout << cost << "\n";
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

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;
set<ll> cube;

void solve() {
    ll x;
    cin >> x;
    bool can = false;
    for (ll y : cube) {
        // cout << y << " ";
        if (cube.find(x-y) != cube.end()) {
            can = true;
            break;
        }
        if (y * 2 >= x)
            break;
    }
    cout << (can ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (ll i = 1; i <= 10000; ++i) {
        cube.insert(i*i*i);
    }
    while (t--) {
        solve();
    }
    return 0;
}

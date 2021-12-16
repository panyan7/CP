#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    ll x, y;
    cin >> x >> y;
    if (y < x) {
        cout << x+y << "\n";
    } else if (y == x) {
        cout << y << "\n";
    } else {
        ll k = y/x, r = y%x;
        cout << k*x+r/2 << "\n";
    }
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

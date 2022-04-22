#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1;

// check long long
void solve() {
    ll x, n;
    cin >> x >> n;
    if (x % 2 == 0) {
        ll ans[4] = {0, -1, 1, 4};
        ll k = n/4;
        if (n % 4 == 2)
            cout << x + 1 << "\n";
        else if (n % 4 == 0)
            cout << x << "\n";
        else if (n % 4 == 3)
            cout << x + (k+1) * 4 << "\n";
        else
            cout << x - k * 4 - 1 << "\n";
    } else {
        ll ans[4] = {0, 1, -1, -4};
        ll k = n/4;
        if (n % 4 == 2)
            cout << x - 1 << "\n";
        else if (n % 4 == 0)
            cout << x << "\n";
        else if (n % 4 == 3)
            cout << x - (k+1) * 4 << "\n";
        else
            cout << x + k * 4 + 1 << "\n";
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

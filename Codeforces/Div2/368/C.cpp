#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;

void solve() {
    cin >> n;
    ll c = 1;
    while (n % 2 == 0) {
        n /= 2;
        c *= 2;
    }
    if (n == 1) {
        if (c >= 4) {
            cout << 3 * (c * n / 4) << " " << 5 * (c * n / 4) << "\n";
        } else {
            cout << "-1\n";
        }
        return;
    }
    ll k = n * n / 2;
    cout << c * k << " " << c * (k + 1) << "\n";
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

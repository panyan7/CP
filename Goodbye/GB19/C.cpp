#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll t, n, s, x;

void solve() {
    if (s == 2 * x) {
        cout << "0\n\n";
        return;
    }
    ll y = (1LL << 47) + (s % 2 == 0 ? 0 : 1);
    s += y;
    x ^= y;
    cout << "3\n";
    cout << y << " " << (2*x-s)/2 << " " << (2*x-s)/2 << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        x = 0; s = 0;
        for (int i = 1; i <= n; ++i) {
            ll a; cin >> a;
            s += a; x ^= a;
        }
        solve();
    }
    return 0;
}

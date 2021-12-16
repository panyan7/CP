#include <bits/stdc++.h>
using namespace std;

int t, n, k1, k2, a, b;

void solve() {
    bool win = false;
    for (int i = 1; i <= k1; ++i) {
        cin >> a;
        if (a == n) win = true;
    }
    for (int i = 1; i <= k2; ++i) {
        cin >> b;
    }
    cout << (win ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k1 >> k2;
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int t, n, a[200001];

void solve() {
    int mn = 1e9+7, mnid = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < mn + i - mnid + 1) {
            mn = a[i];
            mnid = i;
        }
        if (a[i] - mn >= i - mnid + 1) {
            cout << "YES\n";
            cout << mnid << " " << i << "\n";
            return;
        }
    }
    mn = 1e9+7, mnid = n + 1;
    for (int i = n; i >= 1; --i) {
        if (a[i] < mn + mnid - i + 1) {
            mn = a[i];
            mnid = i;
        }
        if (a[i] - mn >= mnid - i + 1) {
            cout << "YES\n";
            cout << i << " " << mnid << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        solve();
    }
    return 0;
}

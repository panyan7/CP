#include <bits/stdc++.h>
using namespace std;

int t, n, k, h[200001];

void solve() {
    int u = h[1]+k, d = h[1];
    for (int i = 2; i <= n; ++i) {
        u = min(h[i]+2*k-1, u+k-1);
        d = max(h[i], d-k+1);
        if (h[i]+k > u || h[i]+k-1 < d) {
            cout << "NO\n";
            return;
        }
    }
    cout << (d == h[n] ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> h[i];
        solve();
    }
    return 0;
}

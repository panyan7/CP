#include <bits/stdc++.h>
using namespace std;

int t, n, m, r[101], b[101];

void solve() {
    int sr[101], sb[101], mr = 0, mb = 0;
    sr[0] = 0; sb[0] = 0;
    for (int i = 1; i <= n; ++i) {
        sr[i] = sr[i-1] + r[i];
        mr = max(mr, sr[i]);
    }
    for (int i = 1; i <= m; ++i) {
        sb[i] = sb[i-1] + b[i];
        mb = max(mb, sb[i]);
    }
    cout << mr+mb << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> r[i];
        cin >> m;
        for (int i = 1; i <= m; ++i) cin >> b[i];
        solve();
    }
    return 0;
}

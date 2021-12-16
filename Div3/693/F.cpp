#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll t, n, m, k;

void solve() {
    cin >> n >> m;
    vector<bool> dp (3, 0);
    map<int, int> s;
    for (int i = 0; i < m; ++i) {
        int r, c; cin >> r >> c;
        s[c-1] |= (1 << (r-1));
    }
    dp[0] = 1;
    int i = 0, b = 0;
    while (s.size() > 0) {
        auto it = s.begin();
        if ((it->first - i) % 2 == 0) {
            swap(dp[1], dp[2]);
        }
        i = it->first;
        b = it->second;
        if (b == 3) {
            if (!dp[0]) break;
            dp[0] = 1; dp[1] = 0; dp[2] = 0;
        } else if (b == 1) {
            swap(dp[1], dp[0]);
            dp[2] = 0;
        } else if (b == 2) {
            swap(dp[2], dp[0]);
            dp[1] = 0;
        } else {
            swap(dp[1], dp[2]);
        }
        s.erase(it);
    }
    if (n - i % 2 == 0) {
        swap(dp[1], dp[2]);
    }
    if (dp[0]) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

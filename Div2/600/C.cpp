#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m;

void solve() {
    cin >> n >> m;
    vector<int> a (n, 0);
    for (auto& x : a) cin >> x;
    sort(all(a));
    ll res = 0;
    vector<ll> dp (n, 0);
    ll sm = 0;
    for (int i = 0; i < n; ++i) {
        sm += a[i];
        dp[i] = sm;
        if (i >= m)
            dp[i] += dp[i-m];
        cout << dp[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

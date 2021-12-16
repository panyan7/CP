#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll t = 1, n, m, k;

void solve() {
    cin >> n;
    vector<ll> c (n, 0), a (n, 0), b (n, 0);
    for (auto& x : c)
        cin >> x;
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;
    vector<ll> dp (n, 0);
    for (int i = 0; i < n; ++i)
        if (a[i] > b[i])
            swap(a[i], b[i]);
    dp[0] = b[1]-a[1];
    // dp[i] == end on i not closed
    for (int i = 1; i < n-1; ++i) {
        if (a[i] != b[i])
            dp[i] += dp[i-1];
        dp[i] += 2 + c[i] - 1 - (b[i+1] - a[i+1]);
        dp[i] = max(dp[i], b[i] - a[i] + 2 + c[i] - 1 - (b[i+1] - a[i+1]));
    }
    if (a[n-1] != b[n-1])
        dp[n-1] = dp[n-2] + 2 + c[n-1] - 1;
    else
        dp[n-1] = 2 + c[n-1] - 1;
    dp[n-1] = max(dp[n-1], b[n-1] - a[n-1] + 2 + c[n-1] - 1);
    ll res = 0;
    for (int i = 1; i < n-1; ++i)
        res = max(dp[i] + (b[i+1] - a[i+1]), res);
    res = max(res, dp[n-1]);
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;
int cost[1005];

// check long long
void solve() {
    cin >> n >> k;
    vector<ll> b(n), c(n);
    vector<unordered_map<ll,ll>> dp(n);
    for (auto& x : b)
        cin >> x;
    for (auto& x : c)
        cin >> x;
    vector<ll> coins(n);
    for (ll i = 0; i < n; i++) {
        coins[i] = cost[b[i]];
    }
    dp[0][0] = 0;
    if (coins[0] <= k)
        dp[0][coins[0]] = c[0];
    for (ll i = 1; i < n; i++) {
        for (auto p : dp[i-1]) {
            if (p.first <= k)
                dp[i][p.first] = max(dp[i][p.first], p.second);
            if (p.first + coins[i] <= k) {
                dp[i][p.first + coins[i]] = max(dp[i][p.first + coins[i]], p.second + c[i]);
            }
        }
    }
    ll res = 0;
    for (auto p : dp[n-1]) {
        res = max(res, p.second);
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    memset(cost, 0x3f, sizeof(cost));
    cost[1] = 0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            if (i + (i/j) <= 1000)
                cost[i + (i/j)] = min(cost[i + (i/j)], cost[i] + 1);
        }
    }
    while (tt--) {
        solve();
    }
    return 0;
}

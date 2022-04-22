#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    vector<bool> dp(n, 0);
    dp[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        if (a[i] == 1)
            dp[i] = 1-dp[i+1];
        else
            dp[i] = 0;
    }
    cout << (dp[0] == 0 ? "First" : "Second") << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

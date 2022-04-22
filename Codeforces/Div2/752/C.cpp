#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<ll> dp;

ll gcd(ll a, ll b) {
    if (b > a)
        swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

// check long long
void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    for (int i = 0; i < n; i++) {
        if (dp[i] == -1)
            break;
        if (a[i] % dp[i] == 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    dp.assign(100005, -1);
    dp[0] = 2;
    for (int i = 1; i < 100005; i++) {
        dp[i] = dp[i-1] * (i+2) / gcd(dp[i-1], (ll)(i+2));
        if (dp[i] > 1e9)
            break;
        //cout << dp[i] << " ";
    }
    while (tt--) {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    string s;
    cin >> s;
    n = s.size();
    vector<ll> a(n+2, 0), p(n+2, 0);
    for (int i = 1; i <= n; i++)
        a[i] = s[i-1] - '0';
    a[n+1] = 1;
    vector<ll> dp(n+2, LLONG_MAX), dp1(n+2, LLONG_MAX);
    for (int i = 1; i <= n+1; i++)
        p[i] = p[i-1] + a[i];
    ll res = LLONG_MAX;
    const ll cost = 1e12;
    for (int i = 0; i <= n; i++) {
        res = min(res, (cost+1) * (p[i] + (n-i+1 - p[n+1] + p[i])));
        if (a[i] == 1 && a[i+1] == 0)
            res = min(res, cost + (cost+1) * (p[i-1] + (n-i - p[n+1] + p[i+1])));
    }
    cout << res << "\n";
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

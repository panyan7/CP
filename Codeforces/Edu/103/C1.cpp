#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
const int MAXN = 1e5+10;
ll a[MAXN], b[MAXN], c[MAXN], dp[MAXN];

// check long long
void solve() {
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        if (a[i] > b[i])
            swap(a[i], b[i]);
    // dp[i] = longest cycle ending in i
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        ll newchain = 2+b[i]-a[i]+c[i]-1;
        ll oldchain;
        if (a[i] == b[i])
            oldchain = 2+c[i]-1;
        else
            oldchain = 2+dp[i-1]-b[i]+a[i]+c[i]-1;
        dp[i] = max(newchain, oldchain);
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res = max(dp[i], res);
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

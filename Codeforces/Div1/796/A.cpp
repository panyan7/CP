#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;
const int MAXN = 2e5+10;
ll a[MAXN], p[MAXN];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        p[i] = p[i-1] + a[i];
    if (k < n) {
        ll res = 0;
        for (int i = k; i <= n; i++)
            res = max(res, p[i]-p[i-k]);
        res += (k-1) * k / 2;
        cout << res << "\n";
        return;
    }
    ll res = p[n]-p[0];
    res += (k-1 + k-n) * n / 2;
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

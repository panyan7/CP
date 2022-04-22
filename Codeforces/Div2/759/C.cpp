#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    sort(a.begin(), a.end());
    m = 0;
    while (m < n && a[m] < 0)
        m++;
    ll resr = 0, resl = 0;
    for (int i = n-1; i >= m; i -= k) {
        resr += 2*a[i];
    }
    if (n-1 >= m)
        resr -= a[n-1];
    for (int i = 0; i < m; i += k) {
        resl -= 2*a[i];
    }
    if (0 < m)
        resl += a[0];
    ll res = resl + resr;
    if (a[0] < 0 && a[n-1] >= 0)
        res += min(-a[0], a[n-1]);
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

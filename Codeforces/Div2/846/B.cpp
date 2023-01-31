#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    ll s = accumulate(a.begin(), a.end(), 0LL);
    ll cur = 0;
    ll res = 1;
    for (int i = 0; i < n-1; i++) {
        cur += a[i];
        res = max(gcd(cur, s-cur), res);
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

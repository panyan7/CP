#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;

void solve() {
    cin >> n >> k;
    vector<ll> a(n), b(n);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i] - (n-i-1);
        total += a[i];
    }
    sort(b.begin(), b.end(), greater<ll>());
    ll res = 0;
    for (int i = 0; i < k; i++)
        res += b[i];
    // cout << total - res << " ";
    res += (k-1)*k/2LL;
    cout << total - res << "\n";
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

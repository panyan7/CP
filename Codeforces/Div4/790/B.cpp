#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    ll s = 0, mn = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        s += x;
        mn = min(mn, x);
    }
    cout << s - mn * n << "\n";
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

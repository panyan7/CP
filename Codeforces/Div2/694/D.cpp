#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(c) (c).begin(), (c).end()

int t, n, m, q;
vector<ll> table;

bool is_sqrt(ll x) {
    ll sq = (ll)round(sqrt(double(x)));
    return sq * sq == x;
}

ll reduce(ll n) {
    ll cnt = 0;
    for (auto& x : table) {
        while (n % x == 0) {
            n /= x;
        }
    }
    return n;
}

bool is_prime(ll n) {
    for (auto& x : table) {
        if (n % x == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    map<ll, ll> mp;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        ++mp[reduce(x)];
    }
    ll cnt1 = 0, cnt2 = 0;
    for (auto& p : mp) {
        if (p.second % 2 == 0 || is_sqrt(p.first)) cnt2 += p.second;
        cnt1 = max(cnt1, p.second);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll w; cin >> w;
        if (w == 0) cout << cnt1 << "\n";
        else cout << max(cnt1, cnt2) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> t;
    for (int i = 2; i <= 1000; ++i) {
        if (is_prime(i)) {
            table.push_back(i);
        }
    }
    for (auto& x : table) {
        x *= x;
    }
    while (t--) {
        solve();
    }
    return 0;
}

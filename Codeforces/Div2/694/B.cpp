#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(c) (c).begin(), (c).end()

int t, n, m, x;

void solve() {
    cin >> n >> x;
    bool one = false;
    ll res = 0;
    vector<pair<ll, ll>> a (n);
    for (auto& b : a) {
        cin >> b.first;
        b.second = 1;
    }
    bool c = false;
    for (int i = 0; i < a.size(); ++i) {
        if (!c && a[i].first % x == 0) {
            res += a[i].first * a[i].second;
            a.push_back({a[i].first/x, a[i].second*x});
        } else {
            c = true;
            res += a[i].first * a[i].second;
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

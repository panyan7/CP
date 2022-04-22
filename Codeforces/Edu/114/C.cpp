#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<ll> a(n);
    ll sm = 0LL;
    for (auto& x : a)
        cin >> x, sm += x;
    cin >> m;
    vector<pll> b(m);
    for (auto& p : b)
        cin >> p.second >> p.first;
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        ll res = 0;
        auto it = lower_bound(a.begin(), a.end(), b[i].second);
        // *it >= b[i].second;
        ll res1, res2;
        if (it == a.end()) {
            res1 = LLONG_MAX;
        } else {
            res1 = max(b[i].first - (sm - *it), 0LL);
        }
        if (it == a.begin()) {
            res2 = LLONG_MAX;
        } else {
            --it;
            res2 = b[i].second - *it + max(b[i].first - (sm - *it), 0LL);
        }
        res = min(res1, res2);
        cout << res << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

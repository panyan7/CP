#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    cin >> n >> m;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    vector<ll> ps(n, 0);
    ll s = 0, ms = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
        ms = max(ms, s);
        ps[i] = ms;
    }
    map<ll,ll> mp;
    for (int i = 0; i < n; ++i) {
        if (mp.find(ps[i]) == mp.end())
            mp[ps[i]] = i; //cout << "mp:" << ps[i] << " " << i << "\n";
    }
    for (int i = 0; i < m; ++i) {
        ll x; cin >> x;
        ll res = 0;
        if (ms <= 0) {
            cout << -1 << " ";
            continue;
        }
        if (x > ms) {
            // cout << "Greater" << " ";
            if (s > 0) {
                res += ((x-ms)/s) * (ll)n;
                x = ((x-ms)%s) + ms;
                if (x > ms) {
                    res += n;
                    x -= s;
                }
                assert(x <= ms);
            } else {
                assert(s <= 0);
                cout << -1 << " ";
                continue;
            }
        }
        assert(x <= ms);
        auto it = mp.lower_bound(x);
        assert(it != mp.end());
        ll id = it->second;
        // cout << "id: " << id << " ";
        res += id;
        cout << res << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

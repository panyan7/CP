#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m;

void solve() {
    cin >> n;
    vector<ll> a (n, 0);
    for (auto& x : a) cin >> x;
    vector<ll> sm (n+1, 0);
    for (int i = 0; i < n; ++i) {
        sm[i+1] = sm[i]+a[i];
    }
    set<ll> s;
    ll res = 0;
    for (int l = 0, r = 0; l < n; ++l) {
        while (r <= n && s.find(sm[r]) == s.end()) {
            s.insert(sm[r]);
            ++r;
        }
        res += (r-l-1);
        s.erase(sm[l]);
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

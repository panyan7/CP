#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll t = 1, n, m, k;
vector<ll> p;

bool check(ll change) {
    ll sm = p[0] + change;
    for (int i = 1; i < n; ++i) {
        if (p[i]*100 > k*sm)
            return false;
        sm += p[i];
    }
    return true;
}

void solve() {
    cin >> n >> k;
    p.assign(n, 0);
    for (auto& x : p)
        cin >> x;
    ll lo = 0, hi = 1e12;
    if (check(lo)) {
        cout << 0 << "\n";
        return;
    }
    while (lo + 1 < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << "\n";
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

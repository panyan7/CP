#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    ll l, r;
    cin >> l >> r;
    // kx >= l, (k+1)x <= r, (k-1)x < l
    ll res = 0;
    for (ll k = 1; k <= (ll)ceil(sqrt(l)); k++) {
        // x >= (l+k-1)/k, x <= r/(k+1), x <= (l-1)/(k-1), x > ceil(sqrt(l))
        ll lb = max((l+k-1)/k, (ll)ceil(sqrt(l))+1);
        ll ub = min(r/(k+1), k == 1 ? r : (l-1)/(k-1));
        res += max(ub - lb + 1, 0LL);
    }
    for (ll x = 1; x <= (ll)ceil(sqrt(l)); x++) {
        // k >= (l+x-1)/x, k <= r/x - 1, k-1 <= (l-1)/x
        ll lb = (l+x-1)/x;
        ll ub = min(r/x-1, (l-1)/x+1);
        if (ub >= lb)
            res++;
        // res += max(ub - lb + 1, 0LL);
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

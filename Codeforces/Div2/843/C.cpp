#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;

void solve() {
    ll x;
    cin >> n >> x;
    ll res = n;
    for (ll b = 0; b < 62; b++) {
        if (!(n & (1LL << b)) && (x & (1LL << b))) {
            cout << "-1\n";
            return;
        }
        if ((n & (1LL << b)) && !(x & (1LL << b))) {
            ll p = n - (n & ((1LL << (b + 1)) - 1LL));
            res = max(res, p + (1LL << (b + 1)));
        }
    }
    for (ll b = 0; b < 62; b++) {
        if ((n & (1LL << b)) && (x & (1LL << b))) {
            if (res > (n | ((1LL << b) - 1))) {
                cout << "-1\n";
                return;
            }
        }
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

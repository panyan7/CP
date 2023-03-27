#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

ll gcd(ll x, ll y) {
    if (x < y)
        swap(x, y);
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

ll lcm(ll x, ll y) {
    return x * y / gcd(x, y);
}

void solve() {
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    int l = 0;
    ll m = 1;
    int res = 0;
    for (int i = 0; i < n; i++) {
        ll nm = lcm(m, b[i]);
        bool ok = true;
        if (nm > m) {
            for (int j = l; j <= i; j++) {
                if (a[j] % (nm / b[j]) != 0)
                    ok = false;
            }
        } else {
            if (a[i] % (nm / b[i]) != 0)
                ok = false;
        }
        m = nm;
        if (!ok) {
            res++;
            l = i;
            m = b[i];
        }
    }
    cout << res + 1 << "\n";
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

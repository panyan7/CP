#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// check long long
void solve() {
    cin >> n >> k;
    vector<ll> x(n);
    for (auto& y : x)
        cin >> y;
    ll d = abs(x[1] - x[0]);
    for (int i = 1; i < n; i++)
        d = gcd(d, abs(x[i] - x[0]));
    bool can = false;
    for (int i = 0; i < n; i++) {
        if ((k - x[i]) % d == 0) {
            can = true;
            break;
        }
    }
    if (can)
        cout << "YES\n";
    else
        cout << "NO\n";
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

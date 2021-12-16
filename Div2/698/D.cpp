#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll t = 1, n, m, k;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    cin >> n >> k;
    vector<ll> x (n, 0);
    for (auto& y : x)
        cin >> y;
    ll g = abs(x[1]-x[0]);
    for (int i = 1; i < n; ++i) {
        g = gcd(g, abs(x[i]-x[0]));
    }
    if (g == 1) {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if ((x[i]-k) % g == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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

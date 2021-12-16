#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1;
const ll MOD = 1e9+7;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

void solve() {
    // check long long
    ll n;
    cin >> n;
    ll res = 2*n;
    ll cum = 1;
    for (int i = 2; i <= 100; i++) {
        cum = lcm(cum, i);
        if (cum > n)
            break;
        res += n / cum;
        res %= MOD;
    }
    cout << res << "\n";
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

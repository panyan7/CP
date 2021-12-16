#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

bool is_prime(ll x) {
    for (ll i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}

// check long long
void solve() {
    cin >> n;
    vector<ll> a(n);
    ll sm = 0;
    ll r = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; sm += a[i];
        if (a[i] % 2 == 1)
            r = i;
    }
    if (!is_prime(sm)) {
        cout << n << "\n";
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << "\n";
    } else {
        cout << n-1 << "\n";
        for (int i = 1; i <= n; i++) {
            if (i-1 != r)
                cout << i << " ";
        }
        cout << "\n";
    }
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

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// check long long
void solve() {
    cin >> n;
    vector<ll> a(n);
    for (auto& x: a)
        cin >> x;
    vector<ll> cnt(31, 0);
    for (int i = 0; i < n; i++) {
        ll x = a[i];
        for (int k = 0; k <= 30; k++) {
            if (x & (1 << k))
                cnt[k]++;
        }
    }
    vector<ll> nz;
    for (int i = 0; i <= 30; i++) {
        if (cnt[i] != 0) {
            nz.push_back(cnt[i]);
        }
    }
    if (nz.size() == 0) {
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        cout << "\n";
    } else {
        ll d = nz[0];
        for (int i = 1; i < (int)nz.size(); i++) {
            d = gcd(nz[i], d);
        }
        for (int i = 1; i <= d; i++) {
            if (d % i == 0)
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

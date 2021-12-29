#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    ll x;
    cin >> x;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (i-1 >= 0 && a[i-1] + a[i] < 2*x) {
            res++;
            a[i] = 5e9;
        }
        if (i-2 >= 0 && a[i-2] + a[i-1] + a[i] < 3*x) {
            res++;
            a[i] = 5e9;
        }
    }
    cout << n-res << "\n";
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

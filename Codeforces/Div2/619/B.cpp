#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    ll mx = -1e9, mn = 1e9;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            if (i-1 >= 0 && a[i-1] != -1) {
                mx = max(mx, a[i-1]);
                mn = min(mn, a[i-1]);
            }
            if (i+1 < n && a[i+1] != -1) {
                mx = max(mx, a[i+1]);
                mn = min(mn, a[i+1]);
            }
        }
    }
    if (mx == -1e9 || mn == 1e9)
        cout << "0 0\n";
    else {
        m = (mx - mn + 1) / 2;
        k = mn + m;
        for (int i = 0; i < n; i++)
            if (a[i] == -1)
                a[i] = k;
        for (int i = 0; i < n-1; i++) {
            m = max(m, abs(a[i] - a[i+1]));
        }
        cout << m << " " << k << "\n";
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

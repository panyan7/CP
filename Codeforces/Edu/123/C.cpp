#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
ll a[5005], p[5005];

// check long long
void solve() {
    ll x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    p[0] = 0;
    for (int l = 1; l <= n; l++) {
        p[l] = -1e14;
        for (int i = 0; i+l <= n; i++) {
            p[l] = max(p[l], a[i+l] - a[i]);
        }
    }
    p[n+1] = -1e14;
    for (int i = n; i >= 0; i--) {
        p[i] = max(p[i], p[i+1]);
    }
    ll res = 0;
    for (int k = 0; k <= n; k++) {
        res = max(res, p[k] + k * x);
        //cout << p[k] << " ";
        cout << res << " ";
    }
    cout << "\n";
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

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll t = 1, n, m, k;

void solve() {
    // check long long
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    ll res = 0;
    for (ll l = 0; l+2 < n; l++) {
        if (a[l+1] == a[l]) {
        } else if (a[l+1] < a[l]) {
            if (a[l+2] == a[l+1]) {
            } else if (a[l+2] < a[l+1]) {
            } else if (a[l+2] < a[l]) {
                res++;
            } else if (a[l+2] == a[l]) {
                res++;
            } else { // a[l+2] > a[l]
                if (l+3 < n && a[l+3] < a[l+2] && a[l+3] > a[l+1])
                    res += 2;
                else
                    res++;
            }
        } else {
            if (a[l+2] == a[l+1]) {
            } else if (a[l+2] > a[l+1]) {
            } else if (a[l+2] > a[l]) {
                res++;
            } else if (a[l+2] == a[l]) {
                res++;
            } else { // a[l+2] < a[l]
                if (l+3 < n && a[l+3] > a[l+2] && a[l+3] < a[l+1])
                    res += 2;
                else
                    res++;
            }
        }
    }
    res += 2 * n - 1;
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

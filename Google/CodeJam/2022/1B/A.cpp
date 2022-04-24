#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = n-1;
    ll mx = 0, res = 0;
    while (l <= r) {
        if (a[l] < mx && a[r] < mx) {
            if (a[l] < a[r]) {
                l++;
            } else {
                r--;
            }
        } else if (a[l] >= mx && a[r] < mx) {
            r--;
        } else if (a[l] < mx && a[r] >= mx) {
            l++;
        } else {
            assert(a[l] >= mx && a[r] >= mx);
            if (a[l] < a[r]) {
                mx = a[l];
                l++;
                res++;
            } else {
                mx = a[r];
                r--;
                res++;
            }
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    for (int ti = 1; ti <= tt; ti++) {
        cout << "Case #" << ti << ": ";
        solve();
    }
    return 0;
}

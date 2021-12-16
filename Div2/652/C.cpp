#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    cin >> n >> k;
    vector<ll> a (n, 0);
    vector<ll> w (k, 0);
    for (auto& x : a) cin >> x;
    for (auto& x : w) cin >> x;
    sort(a.begin(), a.end());
    sort(w.begin(), w.end(), greater<ll>());
    ll res = 0;
    int l = 0, r = n-1;
    for (int i = 0; i < k; ++i) {
        if (w[i] != 1) {
            res += a[l];
            l += w[i]-1;
        }
    }
    for (int i = k-1; i >= 0; --i) {
        if (w[i] == 1) {
            res += 2 * a[r];
            --r;
        } else {
            res += a[r];
            --r;
        }
    }
    assert(r == l-1);
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

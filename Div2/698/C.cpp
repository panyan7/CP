#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    cin >> n;
    vector<ll> d (2*n, 0);
    for (ll& x : d)
        cin >> x;
    sort(d.begin(), d.end());
    for (int i = 0; i < n; ++i) {
        if (d[2*i] != d[2*i+1] || d[2*i] % 2LL != 0) {
            cout << "NO\n";
            return;
        }
    }
    vector<ll> a (n, 0);
    ll sm = 0;
    for (int i = n-1; i >= 0; --i) {
        ll prod = d[2*i] - 2*sm;
        if (prod > 0 && prod % (ll)(2*(i+1)) == 0) {
            a[i] = prod / (ll)(2*(i+1));
            sm += a[i];
        } else {
            cout << "NO\n";
            return;
        }
        if (i < n-1 && a[i] >= a[i+1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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

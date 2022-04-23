#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k, x;

void solve() {
    cin >> n >> x;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    sort(a.begin(), a.end());
    ll s = 0, res = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
        if (s > x)
            break;
        res += (x - s) / (i + 1) + 1;
    }
    cout << res << "\n";
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

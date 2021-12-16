#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;
ll pw[10];

// check long long
void solve() {
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    k++;
    ll res = 0;
    pw[0] = 1;
    for (int i = 1; i < 10; i++)
        pw[i] = pw[i-1] * 10;
    for (int i = 1; i < n; i++) {
        ll p = pow(10, a[i]-a[i-1])-1;
        res += min(p, k) * pw[a[i-1]];
        k -= min(p, k);
        if (k <= 0)
            break;
    }
    res += pw[a[n-1]] * k;
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

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
    sort(a.begin(), a.end());
    ll res = (a[n-1]+2)/3;
    bool has[3] = {0, 0, 0};
    for (int i = 0; i < n; i++)
        has[a[i] % 3] = true;
    bool has_minus_one = false;
    for (int i = 0; i < n; i++)
        if (a[i] == a[n-1]-1)
            has_minus_one = true;
    if (a[n-1] % 3 == 0) {
        if (!has[1] && !has[2])
            cout << res << "\n";
        else
            cout << res+1 << "\n";
    } else if (a[n-1] % 3 == 1) {
        if (!has_minus_one && a[0] != 1)
            cout << res << "\n";
        else if (!has[2])
            cout << res << "\n";
        else
            cout << res+1 << "\n";
    } else if (a[n-1] % 3 == 2) {
        if (!has[1])
            cout << res << "\n";
        else
            cout << res+1 << "\n";
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

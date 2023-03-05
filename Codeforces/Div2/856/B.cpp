#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    for (int i = 0; i < n; i++)
        if (a[i] == 1)
            a[i]++;
    for (int i = 0; i+1 < n; i++) {
        if (a[i+1] % a[i] == 0)
            a[i+1]++;
    }
    for (ll x : a)
        cout << x << " ";
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

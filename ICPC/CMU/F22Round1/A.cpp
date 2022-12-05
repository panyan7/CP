#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            a[i]--;
    sort(a.begin(), a.end(), greater<int>());
    ll res = 0;
    for (int i = 0; i < n-1; i++)
        res += a[i];
    if (n % 2 == 1)
        res += a[n-1];
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

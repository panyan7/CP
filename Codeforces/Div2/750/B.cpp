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
    ll num_one = 0, num_zero = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0)
            num_zero++;
        else if (a[i] == 1)
            num_one++;
    }
    cout << num_one * (1LL << num_zero) << "\n";
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

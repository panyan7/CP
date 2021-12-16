#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t, n, m, k;

void solve() {
    cin >> n;
    vector<int> a (n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> dp = a;
    for (int i = 0; i < n; ++i) {
        dp[i] = max(a[i], dp[i]);
        if (i+a[i] < n) {
            dp[i+a[i]] = max(dp[i+a[i]], dp[i]+a[i+a[i]]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

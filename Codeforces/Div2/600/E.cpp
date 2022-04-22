#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t = 1, n, m;

void solve() {
    cin >> n >> m;
    vector<int> l (n, 0);
    vector<int> r (n, 0);
    for (int i = 0; i < n; ++i) {
        int x, s;
        cin >> x >> s;
        l[i] = x-s;
        r[i] = x+s;
    }
    l.push_back(0);
    r.push_back(0);
    ++n;
    vector<int> dp (m+1, 0);
    for (int k = m-1; k >= 0; --k) {
        dp[k] = m-k;
        for (int i = 0; i < n; ++i) {
            if (k+1 >= l[i] && k+1 <= r[i]) {
                dp[k] = dp[k+1];
                break;
            }
            if (k < l[i]) {
                int d = l[i]-k-1;
                dp[k] = min(dp[k], d+dp[min(m, r[i]+d)]);
            }
        }
    }
    cout << dp[0] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
int dp[5005], a[5005], l[5005], r[5005];
bool has[5005];

// check long long
void solve() {
    cin >> n;
    memset(l, 0x3f, sizeof(l));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }
    // dp[i] == first i people
    for (int i = 1; i <= n; i++) {
        int lm = INT_MAX, rm = INT_MIN, x = 0;
        memset(has, 0, sizeof(has));
        for (int j = i; j >= 1; j--) {
            if (!has[a[j]])
                x ^= a[j];
            has[a[j]] = true;
            // [j, i] form a train
            lm = min(lm, l[a[j]]);
            rm = max(rm, r[a[j]]);
            if (lm >= j && rm <= i) {
                dp[i] = max(dp[i], x + dp[j-1]);
            }
        }
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[n] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

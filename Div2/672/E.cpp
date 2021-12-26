#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
int dp[6405][85][85], pref[85];

// check long long
void solve() {
    cin >> n;
    vector<int> a;
    int cnt = 0, total = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1)
            a.push_back(cnt), cnt = 0;
        else
            cnt++, total++;
    }
    a.push_back(cnt);
    // each move pick some adjacent pair, increase one by 1 and decrease other by 1
    // total protection is 1/2 * sum a[i]*(total-a[i]) = 1/2 * (total^2 - sum a[i]^2)
    // so minimize sum a[i]^2
    memset(dp, 0x3f, sizeof(dp));
    m = a.size();
    pref[0] = a[0];
    for (int i = 1; i < m; i++)
        pref[i] = a[i] + pref[i-1];
    dp[0][0][0] = 0;
    int maxk = n*(n-1)/2;
    for (int i = 0; i < m; i++) {
        // first i entries
        for (int s = 0; s <= total; s++) {
            // sums to j
            for (int k = 0; k <= maxk; k++) {
                // k steps
                for (int h = 0; s+h <= total; h++) {
                    if (dp[k][i][s] >= 1e9)
                        continue;
                    dp[k+abs(pref[i]-(s+h))][i+1][s+h] = min(dp[k+abs(pref[i]-(s+h))][i+1][s+h], dp[k][i][s] + h*h);
                }
            }
        }
    }
    int cur = -1e9, cur_dp;
    for (int k = 0; k <= maxk; k++) {
        cur_dp = (total * total - dp[k][m][total]) / 2;
        cur = max(cur_dp, cur);
        cout << cur << " \n"[k==maxk];
    }
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

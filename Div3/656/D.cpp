#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void umin(int& a, int b) {
    a = min(a, b);
}

// check long long
void solve() {
    cin >> n;
    string s;
    cin >> s;
    int m = log2(n);
    vector<vector<int>> dp(m+1, vector<int>(n+1, 1e9));
    vector<vector<int>> cnt(m+1, vector<int>(n+1, 0));
    for (int i = 0; i < n; i++) {
        dp[m][i] = (s[i] == 'a'+m ? 0 : 1);
    }
    for (int c = 0; c <= m; c++) {
        int knt = 0;
        cnt[c][0] = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != 'a'+c)
                knt++;
            cnt[c][i+1] = knt;
        }
    }
    for (int k = m-1; k >= 0; k--) {
        for (int i = 0; i < (1 << k); i++) {
            int l = i * (1 << (m-k)), r = (i+1) * (1 << (m-k));
            int mid = l + (r-l)/2;
            umin(dp[k][i], cnt[k][mid]-cnt[k][l]+dp[k+1][i*2+1]);
            umin(dp[k][i], cnt[k][r]-cnt[k][mid]+dp[k+1][i*2]);
        }
    }
    cout << dp[0][0] << "\n";
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

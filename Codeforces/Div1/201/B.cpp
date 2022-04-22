#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k, l;
ll dp[105][105][105];
ll nxt[105][105][105];
string f, s1, s2, virus;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void compute_automaton(string s, vector<vector<int>>& aut) {
    int n = s.size();
    vector<int> pi = prefix_function(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            int j = i;
            while (j > 0 && 'A' + c != s[j])
                j = pi[j-1];
            if ('A' + c == s[j])
                j++;
            aut[i][c] = j;
        }
    }
}

void umax(ll& a, ll b) {
    a = max(a, b);
}

void set_dp(int i, int j, int k, int i1, int j1, int k1, int c = 0) {
    // printf("%d %d %d %d %d %d\n", i, j, k, i1, j1, k1);
    if (dp[i][j][k] < dp[i1][j1][k1] + c) {
        nxt[i][j][k] = k1;
    }
    umax(dp[i][j][k], dp[i1][j1][k1] + c);
}

void recover(int i, int j, int k) {
    // printf("%d %d %d\n", i, j, k);
    if (i == 0 || j == 0)
        return;
    if (dp[i][j][k] == dp[i-1][j][k]) {
        recover(i-1, j, k);
        return;
    }
    if (dp[i][j][k] == dp[i][j-1][k]) {
        recover(i, j-1, k);
        return;
    }
    if (s1[i-1] == s2[j-1]) {
        f.push_back(s1[i-1]);
        recover(i-1, j-1, nxt[i][j][k]);
        return;
    }
}

void solve() {
    cin >> s1 >> s2 >> virus;
    n = s1.size(), m = s2.size(), l = virus.size();
    vector<vector<int>> aut(l);
    compute_automaton(virus, aut);
    memset(dp, ~0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0][0] = 0;
        for (int j = 1; j <= m; j++) {
            dp[0][j][0] = 0;
            for (int k = 0; k < l; k++) {
                // umax(dp[i][j][k], dp[i-1][j][k]);
                set_dp(i, j, k, i-1, j, k);
                // umax(dp[i][j][k], dp[i][j-1][k]);
                set_dp(i, j, k, i, j-1, k);
            }
            if (s1[i-1] == s2[j-1]) {
                for (int k = 0; k < l; k++) {
                    //cout << "x";
                    // umax(dp[i][j][aut[k][virus[k]]], dp[i-1][j-1][k]+1);
                    set_dp(i, j, aut[k][s1[i-1]-'A'], i-1, j-1, k, 1);
                }
            }
        }
    }
    ll res = 0;
    for (int k = 0; k < l; k++) {
        umax(res, dp[n][m][k]);
    }
    // cout << res << "\n";
    if (res == 0) {
        cout << "0\n";
        return;
    }
    for (int k = 0; k < l; k++) {
        if (dp[n][m][k] == res) {
            recover(n, m, k);
            break;
        }
    }
    reverse(f.begin(), f.end());
    cout << f << "\n";
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

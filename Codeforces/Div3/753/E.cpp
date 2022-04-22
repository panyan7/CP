#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n >> m;
    string s;
    cin >> s;
    int l = 0, r = 0, u = 0, d = 0;
    int x = 0, y = 0;
    vector<array<int,4>> dp;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'L')
            x--;
        else if (s[i] == 'R')
            x++;
        else if (s[i] == 'U')
            y--;
        else
            y++;
        l = min(x, l);
        r = max(x, r);
        u = min(y, u);
        d = max(y, d);
        dp.push_back({l, r, u, d});
    }
    int bx = 1, by = 1;
    for (int i = 0; i < s.size(); i++) {
        if (dp[i][1]-dp[i][0]+1 > m || dp[i][3]-dp[i][2]+1 > n)
            break;
        bx = m-dp[i][1];
        by = n-dp[i][3];
    }
    cout << by << " " << bx << "\n";
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

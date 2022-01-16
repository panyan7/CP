#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
map<int, vector<array<int,3>>> mp[100010];
map<int, ll> dp[100010];
unordered_set<int> points[100010];
ll x[100010];
const ll INF = 1e17;

// check long long
void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1; i <= n; i++) {
        mp[i].clear();
        dp[i].clear();
        points[i].clear();
    }
    for (int i = 0; i < k; i++) {
        int a, b, c, d, h;
        cin >> a >> b >> c >> d >> h;
        mp[c][d].push_back({a, b, h});
        dp[a][b] = INF;
        dp[c][d] = INF;
        points[a].insert(b);
        points[c].insert(d);
    }
    dp[1][1] = 0;
    dp[n][m] = INF;
    points[1].insert(1);
    points[n].insert(m);
    for (int i = 1; i <= n; i++) {
        for (auto p : mp[i]) {
            for (auto [a, b, h] : p.second) {
                dp[i][p.first] = min(dp[i][p.first], dp[a][b] - h);
            }
        }
        vector<int> pt;
        for (int p : points[i])
            pt.push_back(p);
        sort(pt.begin(), pt.end());
        ll mn = INF; int id = 0;
        for (int y : pt) {
            mn += (y-id) * x[i];
            if (dp[i][y] <= mn) {
                mn = dp[i][y];
            }
            id = y;
            dp[i][y] = min(dp[i][y], mn);
        }
        reverse(pt.begin(), pt.end());
        mn = INF, id = m+1;
        for (int y : pt) {
            mn += (id-y) * x[i];
            if (dp[i][y] <= mn) {
                mn = dp[i][y];
            }
            id = y;
            dp[i][y] = min(dp[i][y], mn);
        }
    }
    if (dp[n][m] >= 1e16)
        cout << "NO ESCAPE\n";
    else
        cout << dp[n][m] << "\n";
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

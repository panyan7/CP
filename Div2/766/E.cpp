#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
map<int, vector<array<int,3>>> mp[100010];
map<int, int> dp[100010];
int x[100010];

// check long long
void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int a, b, c, d, h;
        cin >> a >> b >> c >> d >> h;
        mp[c][d].push_back({a, b, h});
    }
    for (int i = 1; i <= n; i++) {
        for (auto p : mp[i]) {
            for (auto abh : p.second) {
                auto it = mp[abh[0]].lower_bound(d);
                dp[c][d] = dp[]
            }
        }
    }
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

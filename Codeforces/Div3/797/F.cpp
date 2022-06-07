#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    string s;
    cin >> s;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> ok(n+1, 0);
    vector<bool> vis(n, 0);
    ll res = 1;
    for (int i = 0; i < n; i++) {
        if (vis[i])
            continue;
        vis[i] = true;
        vector<int> g = {i};
        int cur = p[i];
        while (cur != i) {
            vis[cur] = true;
            g.push_back(cur);
            cur = p[cur];
        }
        ll min_period = 0, m = g.size();
        for (int i = 1; i <= m; i++) {
            if (m % i != 0)
                continue;
            bool ok = true;
            for (int j = 0; j < m; j++)
                if (s[g[j]] != s[g[(j+i)%m]])
                    ok = false;
            if (ok) {
                min_period = i;
                break;
            }
        }
        res = lcm(res, min_period);
    }
    cout << res << "\n";
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

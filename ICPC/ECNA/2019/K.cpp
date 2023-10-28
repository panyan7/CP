#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<char,int> mp;
    mp['A'] = 0;
    mp['E'] = 1;
    mp['I'] = 2;
    mp['O'] = 3;
    mp['U'] = 4;
    mp['X'] = -1;
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++)
        a[i] = mp[s[i]];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    int d;
    cin >> d;
    for (int i = 0; i < d; i++) {
        int j; cin >> j; j--;
        a[j] = -1;
        c[j] = 0;
    }
    vector<int> cnt(5, 0);
    vector<int> tc(5, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            cnt[a[i]]++;
            tc[a[i]] += c[i];
        }
    }
    string r;
    cin >> r;
    if (r != "X")
        for (char c : r)
            cnt[mp[c]]++;
    vector<vector<int>> dp(5, vector<int>(n, 1e9));
    vector<vector<int>> cost(5, vector<int>(n, 0));
    for (int ch = 0; ch < 5; ch++) {
        for (int i = 0; i < cnt[ch]-1; i++)
            cost[ch][i] = 1e9;
        for (int i = max(cnt[ch]-1, 0); i < n; i++) {
            cost[ch][i] = tc[ch];
            for (int j = 0; j < cnt[ch]; j++) {
                if (a[i-j] == ch)
                    cost[ch][i] -= c[i-j];
            }
        }
        /*
        for (int i = 0; i < n; i++)
            cout << cost[ch][i] << " ";
        cout << "\n";
        */
    }
    vector<bool> vis(5, 0);
    int res = 1e9;
    auto dfs = [&](auto dfs, int level) -> void {
        if (level == 5) {
            res = min(res, *min_element(dp[4].begin(), dp[4].end()));
        } else if (level == 0) {
            for (int ch = 0; ch < 5; ch++) {
                dp[0] = cost[ch];
                vis[ch] = true;
                dfs(dfs, level+1);
                vis[ch] = false;
            }
        } else {
            for (int ch = 0; ch < 5; ch++) {
                if (vis[ch])
                    continue;
                vis[ch] = true;
                int used_cnt = 0;
                for (int ch1 = 0; ch1 < 5; ch1++)
                    if (vis[ch1])
                        used_cnt += cnt[ch1];
                dp[level].assign(n, 1e9);
                for (int i = max(used_cnt-1, 0); i < n; i++) {
                    for (int j = 0; j <= i-cnt[ch]; j++) {
                        dp[level][i] = min(dp[level][i], dp[level-1][j] + cost[ch][i]);
                    }
                }
                dfs(dfs, level+1);
                vis[ch] = false;
            }
        }
    };
    dfs(dfs, 0);
    cout << res << "\n";
    return 0;
}

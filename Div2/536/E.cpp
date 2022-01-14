#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
const int N = 1e5+10;
const int M = 205;
int s[N], t[N], d[N], cd[N];
ll dp[N][M], w[N], cw[N];

struct cmp {
    bool operator()(int a, int b) const {
        if (d[a] == d[b] && w[a] == w[b])
            return a > b;
        if (w[a] == w[b])
            return d[a] > d[b];
        return w[a] > w[b];
    }
};

// check long long
void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
        cin >> s[i] >> t[i] >> d[i] >> w[i];
    vector<pii> re;
    for (int i = 1; i <= k; i++)
        re.push_back({s[i], i});
    sort(re.begin(), re.end());
    int i = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    set<int, cmp> st;
    for (int j = 1; j <= n; j++) {
        while (i < k && re[i].first == j) {
            st.insert(re[i].second);
            pq.push({t[re[i].second], re[i].second});
            i++;
        }
        if (st.size() == 0) {
            cd[j] = j;
            cw[j] = 0;
        } else {
            int c = *st.begin();
            cd[j] = d[c];
            cw[j] = w[c];
        }
        while (!pq.empty() && pq.top().first == j) {
            st.erase(pq.top().second);
            pq.pop();
        }
    }
    // dp[i][j] == first i days, disturb j times, day i+1 can choose
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[cd[i]][0] = min(dp[cd[i]][0], dp[i-1][0] + cw[i]);
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            dp[cd[i]][j] = min(dp[cd[i]][j], dp[i-1][j] + cw[i]);
        }
    }
    ll res = LLONG_MAX;
    for (int j = 0; j <= m; j++)
        res = min(res, dp[n][j]);
    cout << res << "\n";
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

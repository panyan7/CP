#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
const int MAXN = 2e5+10;
ll a[MAXN], b[MAXN], pa[MAXN], pb[MAXN];
ll pos[MAXN], lm[MAXN], rm[MAXN];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        pa[i] = pa[i-1] + a[i];
    for (int i = 1; i <= n; i++)
        pb[i] = pb[i-1] + b[i];
    vector<pll> s(m);
    for (int i = 0; i < m; i++)
        cin >> s[i].first >> s[i].second;
    int l = 1, r = 1;
    int idx = 0;
    set<int> st;
    while (l <= n) {
        r = l;
        while (r <= n && (pa[r] - pa[l-1]) != (pb[r] - pb[l-1]))
            r++;
        if (r > n) {
            cout << "NO\n";
            return;
        }
        for (int i = l; i <= r; i++)
            pos[i] = idx;
        if (l != r)
            st.insert(idx);
        idx++;
        for (int i = l; i <= r; i++) {
            lm[i] = l;
            rm[i] = r;
        }
        l = r+1;
    }
    int N = idx;
    vector<vector<int>> reqs(N);
    vector<int> dep(m, 0);
    for (int i = 0; i < m; i++) {
        auto p = s[i];
        if (lm[p.first] != p.first) {
            reqs[pos[p.first]].push_back(i);
            dep[i]++;
        }
        if (rm[p.second] != p.second) {
            reqs[pos[p.second]].push_back(i);
            dep[i]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < m; i++)
        if (dep[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        auto it1 = st.lower_bound(pos[s[i].first]);
        auto it2 = st.upper_bound(pos[s[i].second]);
        for (auto it = it1; it != it2; it++) {
            for (int j : reqs[*it]) {
                dep[j]--;
                if (dep[j] == 0)
                    q.push(j);
            }
            reqs[*it].clear();
        }
        st.erase(it1, it2);
    }
    cout << (st.size() > 0 ? "NO\n" : "YES\n");
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

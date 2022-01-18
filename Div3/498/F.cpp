#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, s;
ll k;
vector<unordered_map<ll, int>> mp;
vector<vector<ll>> a;
ll res = 0;

void dfs1(int i, int j, ll x) {
    if (i >= n || j >= m)
        return;
    x ^= a[i][j];
    if (i + j == s-1) {
        mp[i][x]++;
        return;
    }
    dfs1(i+1, j, x);
    dfs1(i, j+1, x);
}

void dfs2(int i, int j, ll x) {
    if (i < 0 || j < 0)
        return;
    if (i + j == s-1) {
        res += mp[i][x^k];
        return;
    }
    x ^= a[i][j];
    dfs2(i-1, j, x);
    dfs2(i, j-1, x);
}

// check long long
void solve() {
    cin >> n >> m >> k;
    a.assign(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    s = max(m, n);
    mp.resize(s);
    dfs1(0, 0, 0);
    dfs2(n-1, m-1, 0);
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

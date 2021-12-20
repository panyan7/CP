#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<string> a;
bool vis[55][55];

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m) && a[i][j] != '#';
}

bool check(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m)
        return true;
    if (a[i][j] == 'G')
        return false;
    if (a[i][j] != 'B')
        a[i][j] = '#';
    return true;
}

void dfs(int i, int j) {
    vis[i][j] = true;
    if (valid(i-1, j) && !vis[i-1][j])
        dfs(i-1, j);
    if (valid(i+1, j) && !vis[i+1][j])
        dfs(i+1, j);
    if (valid(i, j-1) && !vis[i][j-1])
        dfs(i, j-1);
    if (valid(i, j+1) && !vis[i][j+1])
        dfs(i, j+1);
}

// check long long
void solve() {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'B') {
                bool ok = check(i-1, j) && check(i+1, j) && check(i, j-1) && check(i, j+1);
                if (!ok) {
                    cout << "No\n";
                    return;
                }
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    if (a[n-1][m-1] != '#') {
        dfs(n-1, m-1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'G' && !vis[i][j]) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
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

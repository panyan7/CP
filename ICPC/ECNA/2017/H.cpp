#include "bits/stdc++.h"
using namespace std;
 
typedef int64_t ll;
int n, m;
vector<string> a;
vector<vector<bool> > vis;
 
void dfs(int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return;
        if (vis[i][j])
            return;
        vis[i][j] = 1;
        if (a[i][j] != '#')
            return;
        for (int i1 = -1; i1 <= 1; i1++) {
            for (int j1 = -1; j1 <= 1; j1++) {
                dfs(i+i1, j+j1);
            }
        }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vis.assign(n, vector<bool>(m, 0));
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && a[i][j] == '#') {
                dfs(i, j);
                res++;
            }
        }
    }
    cout << res << "\n";
    return 0;
}

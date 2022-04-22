#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;
string s;
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    if (v < n && s[v] == 'R' && !visited[v+1])
        dfs(v+1);
    if (v > 0 && s[v-1] == 'L' && !visited[v-1])
        dfs(v-1);
    ans.push_back(v);
}

void solve() {
    cin >> n;
    cin >> s;
    ans.assign(0, 0);
    visited.assign(n+1, false);
    for (int i = 0; i <= n; ++i) 
        if (!visited[i])
            dfs(i);
    vector<int> res (n+1, 1);
    for (int v : ans) {
        if (v < n && s[v] == 'R')
            res[v] = res[v+1] + 1;
        if (v > 0 && s[v-1] == 'L')
            res[v] = res[v-1] + 1;
    }
    for (int v : res)
        cout << v << " ";
    cout << "\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

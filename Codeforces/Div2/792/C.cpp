#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    vector<vector<int>> b = a;
    pii p = {0, 0};
    for (int i = 0; i < n; i++) {
        vector<int> bd;
        sort(a[i].begin(), a[i].end());
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                bd.push_back(j);
            }
        }
        if (bd.size() == 2 && a[i][bd[0]] == b[i][bd[1]] && a[i][bd[1]] == b[i][bd[0]]) {
            p = {bd[0], bd[1]};
        } else if (bd.size() != 0) {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j != p.first && j != p.second && a[i][j] != b[i][j]) {
                cout << "-1\n";
                return;
            }
            if (j == p.first && a[i][j] != b[i][p.second]) {
                cout << "-1\n";
                return;
            }
            if (j == p.second && a[i][j] != b[i][p.first]) {
                cout << "-1\n";
                return;
            }
        }
    }
    cout << p.first+1 << " " << p.second+1 << "\n";
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

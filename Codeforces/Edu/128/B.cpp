#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int r = 0, c = 0;
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'R')
                ok = true;
            if (ok)
                break;
        }
        if (ok) {
            r = i;
            break;
        }
    }
    for (int i = 0; i < m; i++) {
        bool ok = false;
        for (int j = 0; j < n; j++) {
            if (a[j][i] == 'R')
                ok = true;
            if (ok)
                break;
        }
        if (ok) {
            c = i;
            break;
        }
    }
    if (a[r][c] == 'R')
        cout << "YES\n";
    else
        cout << "NO\n";
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

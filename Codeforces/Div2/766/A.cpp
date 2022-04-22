#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    int r, c;
    cin >> n >> m >> r >> c;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    r--, c--;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 'B')
                cnt++;
    if (cnt == 0) {
        cout << "-1\n";
        return;
    }
    if (a[r][c] == 'B') {
        cout << "0\n";
        return;
    }
    int cnt_c = 0, cnt_r = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][c] == 'B')
            cnt_c++;
    }
    for (int j = 0; j < m; j++) {
        if (a[r][j] == 'B')
            cnt_r++;
    }
    if (cnt_c + cnt_r > 0) {
        cout << "1\n";
    } else {
        cout << "2\n";
    }
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

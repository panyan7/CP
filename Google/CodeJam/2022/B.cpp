#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1;

void solve() {
    int a[3][4];
    vector<int> mn(4, INT_MAX);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a[i][j];
            mn[j] = min(mn[j], a[i][j]);
        }
    }
    int total = 1000000;
    if (mn[0] + mn[1] + mn[2] + mn[3] < total) {
        cout << "IMPOSSIBLE";
    } else {
        for (int i = 0; i < 4; i++) {
            cout << min(mn[i], total) << " ";
            total -= min(mn[i], total);
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    for (int t1 = 1; t1 <= tt; t1++) {
        cout << "Case #" << t1 << ": ";
        solve();
    }
    return 0;
}

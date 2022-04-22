#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    vector<vector<int>> f(2, vector<int>(3));
    vector<int> d(8);
    for (int i = 0; i < 2; i++)
        cin >> f[i][2] >> f[i][1] >> f[i][0];
    for (int i = 7; i >= 1; i--)
        cin >> d[i];
    // 1 for PE, 2 for programming, 4 for math
    for (int i = 0; i <= d[3]; i++) {
        for (int j = max(0, d[3]+d[5]-f[1][0]-i); j <= min(d[5], f[0][0]-i); j++) {
            for (int k = max(0, max(d[3]+d[6]-f[1][1]-i, d[5]+d[6]-f[1][2]-j)); k <= min(d[6], min(f[0][1]-i, f[0][2]-j)); k++) {
                vector<vector<int>> temp = f;
                auto ok = [&]() {
                    return temp[0][0] >= 0 && temp[0][1] >= 0 && temp[0][2] >= 0 && temp[1][0] >= 0 && temp[1][1] >= 0 && temp[1][2] >= 0;
                };
                temp[0][0] -= (i+j);
                temp[0][1] -= (i+k);
                temp[0][2] -= (j+k);
                temp[1][0] -= d[3]+d[5]-(i+j);
                temp[1][1] -= d[3]+d[6]-(i+k);
                temp[1][2] -= d[5]+d[6]-(j+k);
                int g1 = min(min(temp[0][0], temp[0][1]), min(temp[0][2], d[7]));
                temp[0][0] -= g1;
                temp[0][1] -= g1;
                temp[0][2] -= g1;
                temp[1][0] -= d[7]-g1;
                temp[1][1] -= d[7]-g1;
                temp[1][2] -= d[7]-g1;
                if (!ok())
                    continue;
                int a1 = min(temp[0][0], d[1]);
                int a2 = min(temp[0][1], d[2]);
                int a3 = min(temp[0][2], d[4]);
                temp[0][0] -= a1;
                temp[0][1] -= a2;
                temp[0][2] -= a3;
                temp[1][0] -= d[1]-a1;
                temp[1][1] -= d[2]-a2;
                temp[1][2] -= d[4]-a3;
                if (!ok())
                    continue;
                cout << g1 << " " << k << " " << j << " " << a3 << " " << i << " " << a2 << " " << a1 << "\n";
                return;
            }
        }
    }
    cout << "-1\n";
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

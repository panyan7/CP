#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
ll res[185];

void solve() {
    ll ang;
    cin >> ang;
    cout << res[ang] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    memset(res, -1, sizeof(res));
    for (int i = 360; i >= 3; i--) {
        for (int j = 1; j <= i-2; j++) {
            if ((180 * j) % i == 0) {
                res[180 * j / i] = i;
            }
        }
    }
    while (tt--) {
        solve();
    }
    return 0;
}

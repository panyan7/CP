#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n >> k;
    vector<int> res(n+1, 0);
    for (int i = 1; i <= n; i++) {
        if (k >= i) {
            res[i] = 2;
            k -= i;
        } else if (k > 0) {
            res[i] = -(2*(i-1) - 2*k + 1);
            k = 0;
        } else {
            res[i] = -1000;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << "\n";
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

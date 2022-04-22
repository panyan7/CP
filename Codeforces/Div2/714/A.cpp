#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    cin >> n >> k;
    if (k >= (n + 1) / 2)
        cout << "-1\n";
    else {
        int cur = n;
        vector<int> res(n, -1);
        for (int i = 0; i < k; i++) {
            res[n-i*2-2] = cur;
            cur--;
        }
        for (int i = 0; i < n; i++) {
            if (res[i] == -1) {
                res[i] = cur;
                cur--;
            }
        }
        for (int i = 0; i < n; i++)
            cout << res[i] << " \n"[i == n-1];
    }
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

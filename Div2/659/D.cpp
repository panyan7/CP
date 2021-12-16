#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m;

void solve() {
    cin >> n;
    vector<int> a (n);
    for (auto& x : a) cin >> x;
    vector<int> cnt (32, 0);
    int xr = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        xr ^= x;
        for (int j = 0; j < 32; ++j) {
            cnt[j] += (x >> j) & 1;
        }
    }
    if (xr == 0) {
        cout << "DRAW\n";
        return;
    }
    int j = 31;
    while ((xr >> j & 1) == 0) --j;
    assert(j >= 0);
    if (cnt[j] % 4 == 3 && (n-cnt[j]) % 2 == 0)
        cout << "LOSE\n";
    else
        cout << "WIN\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

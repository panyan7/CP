#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
int mask[200005][32];

// check long long
void solve() {
    int l, r;
    cin >> l >> r;
    int mask_cur[32];
    for (int j = 0; j < 31; j++) {
        mask_cur[j] = mask[r][j] - mask[l-1][j];
    }
    int res = INT_MAX;
    for (int i = 0; i < 31; i++) {
        res = min(res, mask_cur[i]);
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    for (int i = 1; i <= 200000; i++) {
        for (int j = 0; j < 31; j++) {
            mask[i][j] = mask[i-1][j];
            if (!(i & (1 << j)))
                mask[i][j]++;
        }
    }
    while (tt--) {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ull mod = 1e9+7;

ull t, n, cnt[64];
ull x[500005];

void solve() {
    ull res = 0, s = 0;
    for (int i = 0; i < 64; ++i) {
        s += (cnt[i] * ((1ULL << i) % mod)) % mod;
        s %= mod;
    }
    for (int j = 1; j <= n; ++j) {
        ull sj = 0;
        for (int i = 0; i < 64; ++i) {
            int b = (x[j] >> i) & 1;
            sj += (max(cnt[i], b*n) * ((1ULL << i) % mod)) % mod;
            sj %= mod;
        }
        res += (sj * s) % mod;
        res %= mod;
        ull nj = (n * (x[j] % mod)) % mod;
        res += (sj * nj) % mod;
        res %= mod;
        res += mod - ((sj * sj) % mod);
        res %= mod;
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++i) {
            cin >> x[i];
            for (int j = 0; j < 64; ++j) {
                cnt[j] += ((x[i] >> j) & 1);
            }
        }
        solve();
    }
}

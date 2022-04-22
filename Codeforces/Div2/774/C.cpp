#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;
ll fact[20];

void init() {
    fact[0] = 1;
    fact[1] = 1;
    fact[2] = 2;
    for (int i = 3; i <= 16; i++) {
        fact[i] = fact[i-1] * i;
    }
}

void solve() {
    cin >> n;
    int res = __builtin_popcountll(n);
    for (int i = 0; i < (1 << 15); i++) {
        ll sm = 0;
        for (int j = 0; j < 15; j++) {
            if (i & (1 << j)) {
                sm += fact[j];
            }
        }
        if (sm > n)
            continue;
        res = min(res, (int)__builtin_popcountll(n - sm) + __builtin_popcountll(i));
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

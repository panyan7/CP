#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
const ull i19 = 10000000000000000000ULL;
ull p[20];
unordered_map<ull, ll> mem;

ll f(ull x) {
    if (mem.count(x))
        return mem[x];
    if (x >= p[n-1])
        return 0;
    ull y = x;
    vector<int> cnt(10, 0);
    while (y) {
        cnt[y%10]++;
        y /= 10;
    }
    ll res = 1e9;
    for (int i = 9; i >= 2; i--) {
        if (cnt[i] == 0)
            continue;
        res = min(res, f(x*(ull)i));
    }
    mem[x] = res+1;
    return res+1;
}

void solve() {
    ull x;
    cin >> n >> x;
    ll res = f(x);
    if (res >= 1e9)
        cout << "-1\n";
    else
        cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> tt;
    p[0] = 1;
    for (int i = 1; i <= 19; i++)
        p[i] = p[i-1] * 10ULL;
    while (tt--) {
        solve();
    }
    return 0;
}

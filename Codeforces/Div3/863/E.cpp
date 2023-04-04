#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;
ll p[20];

void solve() {
    cin >> k;
    ll lo = 0, hi = 1e14;
    auto check = [&](ll x) {
        ll cnt = 0;
        for (int i = 14; i >= 0; i--) {
            int d = (x / p[i]) % 10;
            if (d > 4)
                cnt += (d-1) * pow(9LL, i);
            else
                cnt += d * pow(9LL, i);
            if (d == 4)
                return cnt;
        }
        return cnt;
    };
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid + 1) >= k + 1)
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    p[0] = 1;
    for (int i = 1; i <= 18; i++)
        p[i] = p[i-1] * 10LL;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

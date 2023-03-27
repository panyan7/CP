#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;

void solve() {
    auto get_cnt = [&](ll cost) {
        return (cost+1) * (cost+1);
    };
    cin >> n;
    ll lo = 0, hi = 1e9+1000LL;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2LL;
        if (get_cnt(mid) >= n)
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << "\n";
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

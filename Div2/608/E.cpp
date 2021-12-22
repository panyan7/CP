#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k, b;

ll count_num(ll x) {
    ll res = 1LL; ll y = x;
    ll c = 0LL;
    while (y) {
        c++;
        y >>= 1LL;
    }
    for (int i = 1; (x << i) <= n; i++) {
        ll mn = (x << i);
        ll mx = (x << i) + (1LL << i) - 1LL;
        if (mx <= n)
            res += (1LL << i);
        else
            res += n-mn+1LL;
    }
    if (x % 2LL == 0LL)
        res += count_num(x+1LL);
    return res;
}

// check long long
void solve() {
    cin >> n >> k;
    m = n;
    while (m) {
        b++;
        m >>= 1;
    }
    if (count_num(n) >= k) {
        cout << n << "\n";
        return;
    }
    if (n > 1 && count_num(n-1) >= k) {
        cout << n-1 << "\n";
        return;
    }
    // odd: prefix has x
    // even: prefix has x or x+1
    // first binary search on odd
    ll lo = 0, hi = n/2;
    while (lo + 1 < hi) {
        ll mid = lo + (hi-lo)/2;
        //cout << mid*2 << ":" << count_num(mid*2) << "\n";
        if (count_num(mid*2) < k)
            hi = mid;
        else
            lo = mid;
    }
    ll res = lo * 2;
    lo = 0, hi = n/2;
    // then binary search on even
    while (lo + 1 < hi) {
        ll mid = lo + (hi-lo)/2;
        if (count_num(mid*2+1) < k)
            hi = mid;
        else
            lo = mid;
    }
    res = max(res, lo * 2 + 1);
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

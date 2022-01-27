#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k, q;
int a[1000005], query[1000005];

// check long long
void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> query[i];
    }
    int lo = 0, hi = n+1;
    auto check = [&](int mid) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= mid)
                cnt++;
        }
        for (int i = 0; i < q; i++) {
            if (query[i] < 0) {
                if (cnt >= -query[i])
                    cnt--;
            } else {
                if (query[i] <= mid)
                    cnt++;
            }
        }
        return cnt > 0;
    };
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    if (hi > n)
        cout << 0 << "\n";
    else
        cout << hi << "\n";
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

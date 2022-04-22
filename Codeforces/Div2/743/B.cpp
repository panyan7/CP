#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;
    if (a[0] < b[0]) {
        cout << "0\n";
    } else {
        int res = INT_MAX;
        vector<int> amin(n), bmax(n);
        int mx = 0, mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            mx = max(mx, b[i]);
            bmax[i] = mx;
            mn = min(mn, a[i]);
            amin[i] = mn;
        }
        int lo = 0, hi = n-1;
        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            bool can = false;
            for (int i = 0; i <= mid; i++) {
                if (amin[i] < bmax[mid-i]) {
                    can = true;
                    break;
                }
            }
            if (can) hi = mid;
            else lo = mid;
        }
        cout << hi << "\n";
    }
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

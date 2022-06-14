#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k, s;

void solve() {
    cin >> n >> s;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    vector<int> p(n+1, 0);
    for (int i = 0; i < n; i++)
        p[i+1] = p[i] + a[i];
    auto check = [&](int mid) {
        mid = n - mid;
        for (int i = 0; i+mid <= n; i++) {
            if (p[i+mid] - p[i] <= s)
                return true;
        }
        return false;
    };
    int lo = 0, hi = n;
    if (p[n] - p[0] == s)
        hi = 0;
    else if (p[n] - p[0] < s)
        hi = -1;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << "\n";
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

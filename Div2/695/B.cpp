#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m;

void solve() {
    cin >> n;
    vector<int> a (n, 0);
    for (auto& x : a) cin >> x;
    int res = 0;
    vector<int> h (n, 0);
    for (int i = 1; i < n-1; ++i) {
        if (a[i] < a[i+1] && a[i] < a[i-1]) {
            ++res;
            h[i] = -1;
        }
        if (a[i] > a[i+1] && a[i] > a[i-1]) {
            ++res;
            h[i] = 1;
        }
    }
    int d = 0;
    for (int i = 1; i < n-1; ++i) {
        // set a[i] = a[i+1]
        int d1 = 0, ai = a[i+1];
        if (h[i] != 0) ++d1;
        if (h[i+1] != 0) ++d1;
        if (h[i-1] == -1 && a[i+1] <= a[i-1]) ++d1;
        if (h[i-1] == 1 && a[i+1] >= a[i-1]) ++d1;
        if (h[i-1] == 0 && i > 1 && a[i-2] < a[i-1] && a[i+1] < a[i-1]) --d1;
        if (h[i-1] == 0 && i > 1 && a[i-2] > a[i-1] && a[i+1] > a[i-1]) --d1;
        d = max(d1, d);
        // set a[i] = a[i-1]
        int d2 = 0; ai = a[i-1];
        if (h[i] != 0) ++d2;
        if (h[i-1] != 0) ++d2;
        if (h[i+1] == -1 && ai <= a[i+1]) ++d2;
        if (h[i+1] == 1 && ai >= a[i+1]) ++d2;
        if (h[i+1] == 0 && i < n-2 && a[i+2] < a[i+1] && ai < a[i+1]) --d2;
        if (h[i+1] == 0 && i < n-2 && a[i+2] > a[i+1] && ai > a[i+1]) --d2;
        d = max(d2, d);
    }
    cout << max(res-d, 0) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

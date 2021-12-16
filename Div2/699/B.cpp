#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll t = 1, n, m, k;

void solve() {
    cin >> n >> k;
    vector<int> h(n, 0);
    for (auto& x : h)
        cin >> x;
    int ans = -1;
    for (int i = 0; i < k; ++i) {
        bool ok = false;
        for (int j = 1; j < n; ++j) {
            if (h[j] > h[j-1]) {
                ++h[j-1];
                ok = true;
                ans = j;
                break;
            }
        }
        if (!ok) {
            ans = -1;
            break;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

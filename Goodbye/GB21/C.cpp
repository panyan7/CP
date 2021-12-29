#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            // fix a[i] and a[j]
            int cnt = 0;
            double d = (double)(a[j]-a[i]) / (j-i);
            for (int k = 0; k < n; k++) {
                if ((double)a[i] + (k-i) * d != (double)a[k])
                    cnt++;
            }
            res = min(res, cnt);
        }
    }
    if (n <= 2)
        res = 0;
    cout << res << "\n";
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

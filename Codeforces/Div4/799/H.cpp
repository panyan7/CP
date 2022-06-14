#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<bool> vis(n, 0);
    int res = 0, b = 0, l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i])
            continue;
        vis[i] = true;
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (a[j] == a[i]) {
                cnt++;
                vis[j] = true;
            } else
                cnt--;
            if (cnt > res) {
                res = cnt;
                b = a[i];
                l = i;
                r = j;
            }
            if (cnt < 0)
                break;
        }
    }
    cout << b << " " << l+1 << " " << r+1 << "\n";
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

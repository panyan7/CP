#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
int lst[150005], dist[150005];

// check long long
void solve() {
    cin >> n;
    vector<int> a(n);
    memset(lst, ~0x3f, sizeof(lst));
    memset(dist, 0, sizeof(dist));
    for (auto& x : a)
        cin >> x;
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        res = min(res, i - lst[a[i]]);
        lst[a[i]] = i;
    }
    if (res < 1e9)
        cout << n-res << "\n";
    else
        cout << -1 << "\n";
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

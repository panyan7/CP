#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
ll a[200005];

// check long long
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        a[i] -= i;
    a[n+1] = -1e15;
    vector<ll> d, d1;
    int cnt = 0, best_cnt = 0, res = INT_MAX;
    for (int i = 1; i <= n; i++) {
        auto it = upper_bound(d.begin(), d.end(), a[i]);
        if (it == d.end()) {
            d.push_back(a[i]);
            cnt = 0;
        } else {
            if (a[i] == d.back()-1 && a[i-1] != d.back()) {
                cnt++;
            }
            *it = a[i];
        }
        best_cnt = max(best_cnt, cnt);
    }
    res = min(res, n-1-(int)d.size()-best_cnt);
    cnt = 0, best_cnt = 0;
    d.clear();
    for (int i = n; i >= 1; i--) {
        auto it = upper_bound(d.begin(), d.end(), a[i], greater<ll>());
        if (it == d.end()) {
            d.push_back(a[i]);
            cnt = 0;
        } else {
            if (a[i] == d.back()+1 && a[i+1] != d.back()) {
                cnt++;
            }
            *it = a[i];
        }
        best_cnt = max(best_cnt, cnt);
    }
    res = min(res, n-1-(int)d.size()-best_cnt);
    cout << max(res, 0) << "\n";
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

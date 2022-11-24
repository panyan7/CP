#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    ll cnt0 = 0, cnt1 = 0;
    ll res = 0, inv = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            cnt0++;
            inv += cnt1;
        } else {
            cnt1++;
        }
    }
    res = max(res, inv);
    cnt0 = 0, cnt1 = 0, inv = 0;
    vector<int> b = a;
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            b[i] = 1;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            cnt0++;
            inv += cnt1;
        } else {
            cnt1++;
        }
    }
    res = max(res, inv);
    cnt0 = 0, cnt1 = 0, inv = 0;
    b = a;
    for (int i = n-1; i >= 0; i--) {
        if (b[i] == 1) {
            b[i] = 0;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            cnt0++;
            inv += cnt1;
        } else {
            cnt1++;
        }
    }
    res = max(res, inv);
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

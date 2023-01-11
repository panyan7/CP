#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            pos += a[i];
            neg = max(neg - a[i], 0LL);
        } else if (a[i] < 0) {
            neg += -a[i];
            pos = max(pos + a[i], 0LL);
        }
    }
    cout << pos + neg << "\n";
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

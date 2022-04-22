#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;
    ll am = 0, bm = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i])
            swap(a[i], b[i]);
        am = max(am, a[i]);
        bm = max(bm, b[i]);
    }
    cout << am * bm << "\n";
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

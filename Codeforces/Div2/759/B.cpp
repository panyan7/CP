#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<ll> a(n);
    ll mx = 0;
    for (auto& x : a)
        cin >> x, mx = max(x, mx);
    int res = 0;
    int i = n-1;
    while (i >= 0) {
        if (a[i] == mx) {
            break;
        }
        int j = i;
        while (j >= 0 && a[j] <= a[i])
            j--;
        res++;
        i = j;
    }
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

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
    int mx = 0, mx2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > mx) {
            mx2 = mx;
            mx = a[i];
        } else if (a[i] > mx2) {
            mx2 = a[i];
        }
    }
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        if (a[i] == mx)
            res[i] = a[i] - mx2;
        else
            res[i] = a[i] - mx;
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
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

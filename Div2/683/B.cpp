#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n >> m;
    vector<int> a(n*m);
    for (auto& x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int sm = 0;
    for (int i = 0; i < n*m; i++)
        sm += a[i];
    int mn = 0;
    for (int i = 0; i+1 < n*m; i += 2) {
        mn = min(mn, mn + a[i] + a[i+1]);
    }
    cout << sm-2*mn << "\n";
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

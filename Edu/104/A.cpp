#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n);
    int mn = INT_MAX;
    for (auto& x : a) {
        cin >> x;
        mn = min(mn, x);
    }
    int res = 0;
    for (auto x : a) {
        if (x > mn)
            ++res;
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

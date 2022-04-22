#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m, d;

void solve() {
    cin >> n >> d;
    vector<int> a (n, 0);
    int mn = INT_MAX, id = -1;
    bool check = true;
    for (auto& x : a) cin >> x;
    for (int i = 0; i < n; ++i) {
        if (a[i] > d) check = false;
        if (a[i] < mn) {
            mn = a[i];
            id = i;
        }
    }
    if (check) {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (i != id && a[i] + mn <= d) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
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

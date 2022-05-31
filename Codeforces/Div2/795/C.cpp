#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n >> k;
    string s;
    cin >> s;
    int sm = 0;
    for (int i = 0; i < n; i++)
        sm += (s[i]-'0');
    int l = 0, r = n-1;
    for (l = 0; l < n; l++) {
        if (s[l] == '1')
            break;
    }
    for (r = n-1; r >= 0; r--) {
        if (s[r] == '1')
            break;
    }
    if (l == n || r == -1) {
        cout << sm * 11 << "\n";
        return;
    }
    if (l == r) { // only one
        if (k >= (n-1-r)) {
            cout << (sm - 1) * 10 + sm << "\n";
        } else if (k >= l) {
            cout << sm * 10 + sm - 1 << "\n";
        } else {
            cout << sm * 11 << "\n";
        }
    } else {
        if (k >= l + (n-1-r)) {
            cout << (sm - 1) * 11 << "\n";
        } else if (k >= n-1-r) {
            cout << (sm - 1) * 10 + sm << "\n";
        } else if (k >= l) {
            cout << sm * 10 + sm - 1 << "\n";
        } else {
            cout << sm * 11 << "\n";
        }
    }
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

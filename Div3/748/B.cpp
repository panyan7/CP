#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    string s;
    cin >> s;
    n = s.size();
    int n0 = -1, n5 = -1;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '0') {
            n0 = i;
            break;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '5') {
            n5 = i;
            break;
        }
    }
    int res = INT_MAX;
    if (n0 != -1) {
        for (int i = n0-1; i >= 0; i--) {
            if (s[i] == '5' || s[i] == '0') {
                res = min(res, n-i-2);
                break;
            }
        }
    }
    if (n5 != -1) {
        for (int i = n5-1; i >= 0; i--) {
            if (s[i] == '2' || s[i] == '7') {
                res = min(res, n-i-2);
                break;
            }
        }
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

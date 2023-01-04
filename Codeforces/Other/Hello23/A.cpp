#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    string s;
    cin >> s;
    int l = 0, r = n-1;
    while (l < n && s[l] == 'L')
        l++;
    while (r >= 0 && s[r] == 'R')
        r--;
    if (l == n || r == -1) {
        cout << "-1\n";
        return;
    }
    if (l > r) {
        cout << r+1 << "\n";
        return;
    }
    cout << "0\n";
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

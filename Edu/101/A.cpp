#include <bits/stdc++.h>
using namespace std;

int t;
string s;

void solve() {
    int n = s.size();
    if (n % 2 == 1 || s[0] == ')' || s[n-1] == '(') {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        s.resize(0);
        cin >> s;
        solve();
    }
    return 0;
}

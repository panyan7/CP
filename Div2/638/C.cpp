#include <bits/stdc++.h>
using namespace std;

int t, n, k;
string s;

void solve() {
    cin >> n >> k;
    s.resize(0);
    cin >> s;
    sort(s.begin(), s.end());
    string ans;
    cout << s[k-1];
    if (s[k-1] != s[0] || k == n) {
        cout << "\n";
    } else if (s[k] != s[n-1]) {
        cout << s.substr(k, n-k) << "\n";
    } else {
        for (int i = 0; i < (n-1)/k; ++i)
            cout << s[k];
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
        solve();
    return 0;
}

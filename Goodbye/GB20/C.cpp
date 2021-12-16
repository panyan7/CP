#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

int t;
string s;

void solve() {
    int n = s.size(), res = 0;
    for (int i = 0; i < n-1; ++i) {
        if (s[i] == s[i+1] || (i > 0 && s[i-1] == s[i+1])) {
            ++res;
            s[i+1] = '0';
        }
    }
    cout << res << "\n";
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
}

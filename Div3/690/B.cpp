#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;

void solve() {
    if (s.size() < 4) {
        cout << "NO\n";
        return;
    }
    string r = "2020";
    int a = 0, b = 0;
    for (int i = 0; i < 4; ++i) {
        if (s[i] == r[i]) ++a;
        else break;
    }
    for (int i = 0; i < 4; ++i) {
        if (s[n-i-1] == r[3-i]) ++b;
        else break;
    }
    cout << (a+b<4 ? "NO\n" : "YES\n");
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        solve();
    }
}

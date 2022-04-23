#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    string s;
    cin >> s;
    bool ok = true;
    if (s.size() == 1) {
        cout << "NO\n";
        return;
    }
    if (s[0] != s[1])
        ok = false;
    if (s[s.size()-1] != s[s.size()-2])
        ok = false;
    for (int i = 1; i < s.size()-1; i++) {
        if (s[i] != s[i-1] && s[i] != s[i+1])
            ok = false;
    }
    cout << (ok ? "YES\n" : "NO\n");
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

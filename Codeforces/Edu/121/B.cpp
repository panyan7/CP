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
    for (int i = n-2; i >= 0; i--) {
        int sm = s[i]-'0' + s[i+1]-'0';
        if (s[i]-'0' + s[i+1]-'0' >= 10) {
            s[i] = '1';
            s[i+1] = (sm % 10) + '0';
            cout << s << "\n";
            return;
        }
    }
    for (int i = 0; i < n-1; i++) {
        int sm = s[i]-'0' + s[i+1]-'0';
        string f = s.substr(i+2, n-i-2);
        if (sm >= s[i]-'0') {
            s[i] = sm + '0';
            cout << s.substr(0, i+1);
            cout << f << "\n";
            return;
        }
    }
    s[n-2] = s[n-2] + s[n-1]-'0';
    cout << s.substr(0, n-1) << "\n";
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

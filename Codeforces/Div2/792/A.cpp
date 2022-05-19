#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    string s;
    cin >> s;
    if (s.size() == 2) {
        cout << s[1] << "\n";
    } else {
        char c = '9';
        for (int i = 0; i < s.size(); i++)
            c = min(c, s[i]);
        cout << c << "\n";
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

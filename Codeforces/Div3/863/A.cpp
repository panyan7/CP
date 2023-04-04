#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    string s;
    char d;
    cin >> n >> d;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] < d) {
            cout << s.substr(0, i) << d << s.substr(i, n-i) << "\n";
            return;
        }
    }
    cout << s << d << "\n";
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

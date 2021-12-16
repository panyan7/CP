#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define all(c) (c).begin(), (c).end()

int t = 1, n, m, k;

void solve() {
    cin >> n;
    string s;
    cin >> s;
    bool fd = false;
    for (int i = 0; i < n-6; ++i) {
        if (s.substr(i, 7) == "abacaba") {
            fd = true;
            break;
        }
    }
    if (fd) {
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

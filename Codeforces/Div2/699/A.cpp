#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    int px, py;
    cin >> px >> py;
    string s;
    cin >> s;
    int u = 0, d = 0, r = 0, l = 0;
    for (char c : s) {
        if (c == 'U') ++u;
        else if (c == 'D') ++d;
        else if (c == 'R') ++r;
        else ++l;
    }
    if ((py > 0 && u < py) || (py < 0 && d < -py) || (px > 0 && r < px) || (px < 0 && l < -px))
        cout << "NO\n";
    else
        cout << "YES\n";
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

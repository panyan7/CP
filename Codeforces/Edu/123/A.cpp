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
    bool has[3] = {0, 0, 0};
    bool ok = true;
    for (char c : s) {
        if (c == 'r')
            has[0] = true;
        else if (c == 'g')
            has[1] = true;
        else if (c == 'b')
            has[2] = true;
        else if (c == 'R') {
            if (!has[0])
                ok = false;
        } else if (c == 'G') {
            if (!has[1])
                ok = false;
        } else {
            if (!has[2])
                ok = false;
        }
    }
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
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

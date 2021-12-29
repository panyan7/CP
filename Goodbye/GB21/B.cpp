#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    string s;
    cin >> s;
    string a, b;
    a += s[0];
    b += s[0];
    for (int i = 1; i < n; i++) {
        if (s[i-1] >= s[i]) {
            a += s[i];
            b += s[i];
        } else {
            break;
        }
    }
    reverse(b.begin(), b.end());
    if (a.size() >= 2 && a[0] == a[1]) {
        cout << a[0] << a[0] << "\n";
    } else {
        string res = a + b;
        cout << res << "\n";
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

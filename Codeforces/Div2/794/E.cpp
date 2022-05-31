#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
int h[200005];

void solve() {
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < 2*n; i++)
        h[i+1] = h[i] + (s[i] == '(' ? 1 : -1);
    if (*min_element(h+1, h+2*n+1) >= 0) {
        cout << "0\n";
        return;
    }
    // check if 1 is ok
    int l = 1, r = 2*n;
    for (l = 1; l <= 2*n; l++) {
        if (h[l] < 0)
            break;
    }
    for (r = 2*n; r >= 1; r--) {
        if (h[r] < 0)
            break;
    }
    l = max_element(h, h+l+1) - h;
    r = max_element(h+r, h+2*n+1) - h;
    // reverse l+1 to r
    string t = s;
    for (int i = l+1; i <= r; i++)
        t[i-1] = s[r-(i-l-1)-1];
    int i2 = max_element(h+1, h+2*n+1) - h;
    for (int i = 0; i < 2*n; i++)
        h[i+1] = h[i] + (t[i] == '(' ? 1 : -1);
    if (*min_element(h+1, h+2*n+1) >= 0) {
        cout << "1\n";
        cout << l+1 << " " << r << "\n";
        return;
    }
    // need 2 operations
    cout << "2\n";
    cout << 1 << " " << i2 << "\n";
    cout << i2+1 << " " << 2*n << "\n";
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

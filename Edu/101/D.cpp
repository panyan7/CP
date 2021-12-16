#include <bits/stdc++.h>
using namespace std;

int t, n, a[200001];

void solve() {
    if (n == 3) {
        cout << "2\n3 2\n3 2\n";
        return;
    }
    int c = 2, l = c, op = 0;
    for (int i = 2; i <= n-1; ++i) {
        if (i == c) {
            l = c;
            c = c * c;
        } else {
            // cout << i << " " << n << "\n";
            ++op;
        }
    }
    c = l;
    op += 2;
    if (n > 65536) {
        op += 2;
    }
    if (n > 256) {
        op += 2;
    }
    if (n > 16) {
        op += 2;
    }
    if (n > 4) {
        op += 2;
    }
    cout << op << "\n";
    c = 2, l = c, op = 0;
    for (int i = 2; i <= n-1; ++i) {
        if (i == c) {
            l = c;
            c = c * c;
        } else {
            cout << i << " " << n << "\n";
        }
    }
    c = l;
    cout << n << " " << c << "\n";
    cout << n << " " << c << "\n";
    if (n > 65536) {
        cout << "65536 256\n65536 256\n";
    }
    if (n > 256) {
        cout << "256 16\n256 16\n";
    }
    if (n > 16) {
        cout << "16 4\n16 4\n";
    }
    if (n > 4) {
        cout << "4 2\n4 2\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        solve();
    }
    return 0;
}

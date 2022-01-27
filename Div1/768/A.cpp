#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    // 6e4
    cin >> n >> k;
    if (k == n-1) {
        if (n == 4)
            cout << "-1\n";
        else {
            for (int i = 2; i < n/2; i++) {
                if (i != 3)
                    cout << i << " " << n-i-1 << "\n";
            }
            cout << 0 << " " << n-1-3 << "\n";
            cout << 3 << " " << 1 << "\n";
            cout << n-1 << " " << n-2 << "\n";
        }
    } else if (k == 0) {
        for (int i = 0; i < n/2; i++)
            cout << i << " " << n-1-i << "\n";
    } else {
        for (int i = 1; i < n/2; i++) {
            if (i != k && n-i-1 != k)
                cout << i << " " << n-i-1 << "\n";
        }
        cout << 0 << " " << n-k-1 << "\n";
        cout << k << " " << n-1 << "\n";
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

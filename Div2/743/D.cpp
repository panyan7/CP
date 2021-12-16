#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<int> a(n);
    int sm = 0;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (sm == 0 && (i % 2 == 1)) {
            index = i;
        }
        cin >> a[i];
        sm ^= a[i];
    }
    if (sm == 0) {
        if (n % 2 == 1) {
            cout << "YES\n";
            cout << n-1 << "\n";
            for (int i = 1; i+2 <= n; i += 2) {
                cout << i << " ";
            }
            for (int i = n-2; i >= 1; i -= 2) {
                cout << i << " ";
            }
            cout << "\n";
        } else {
            if (index == -1) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
                cout << n-2 << "\n";
                for (int i = 1; i+2 <= index; i += 2) {
                    cout << i << " ";
                }
                for (int i = index-2; i >= 1; i -= 2) {
                    cout << i << " ";
                }
                for (int i = index+1; i+2 <= n; i += 2) {
                    cout << i << " ";
                }
                for (int i = n-2; i >= index+1; i -= 2) {
                    cout << i << " ";
                }
                cout << "\n";
            }
        }
    } else {
        cout << "NO\n";
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

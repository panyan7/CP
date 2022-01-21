#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
 
int tt = 1, n, m, k;
 
// check long long
void solve() {
    char c;
    cin >> n;
    cin >> c;
    string s;
    cin >> s;
    bool can = true;
    for (int i = 0; i < n; i++) {
        if (s[i] != c) {
            can = false;
            break;
        }
    }
    if (can) {
        cout << "0\n";
        return;
    }
    for (int i = n/2; i < n; i++) {
        if (s[i] == c) {
            cout << "1\n";
            cout << i+1 << "\n";
            return;
        }
    }
    cout << "2\n";
    cout << n << " " << n-1 << "\n";
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

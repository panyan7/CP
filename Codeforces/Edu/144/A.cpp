#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
string f;

void solve() {
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i+n <= f.size(); i++) {
        if (f.substr(i,n) == s) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    for (int i = 1; i <= 60; i++) {
        if (i % 3 == 0)
            f.push_back('F');
        if (i % 5 == 0)
            f.push_back('B');
    }
    while (tt--) {
        solve();
    }
    return 0;
}

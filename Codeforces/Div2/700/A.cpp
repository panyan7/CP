#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    string s;
    cin >> s;
    string res;
    for (int i = 0; i < s.size(); ++i) {
        if (i % 2 == 0) {
            if (s[i] != 'a')
                res += 'a';
            else
                res += 'b';
        } else {
            if (s[i] != 'z')
                res += 'z';
            else
                res += 'y';
        }
    }
    cout << res << "\n";
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

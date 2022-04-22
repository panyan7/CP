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
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        res += (s[i] - '0');
        if (s[i] != '0' && i+1 != s.size())
            res++;
    }
    cout << res << "\n";
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

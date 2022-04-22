#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    string p;
    cin >> p;
    string s;
    cin >> s;
    map<char,int> mp;
    for (int i = 0; i < p.size(); i++) {
        mp[p[i]] = i;
    }
    int res = 0;
    for (int i = 0; i < s.size()-1; i++) {
        res += abs(mp[s[i]] - mp[s[i+1]]);
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

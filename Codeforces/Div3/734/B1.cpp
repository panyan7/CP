#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
 
ll t = 1, n, m, k;
 
void solve() {
    // check long long
    string s;
    cin >> s;
    n = s.size();
    map<char, int> mp;
    for (char c : s) {
        mp[c]++;
    }
    int n1 = 0, n2 = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        if (mp[c] == 1)
            n1++;
        else if (mp[c] > 1)
            n2++;
    }
    cout << n1 / 2 + n2 << "\n";
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

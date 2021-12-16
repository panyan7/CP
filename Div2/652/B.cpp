#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define all(c) (c).begin(), (c).end()

int t = 1, n, m, k;

void solve() {
    string s;
    cin >> n >> s;
    // 10101 -> 01
    // 0101 -> 001
    // 1010 -> 0
    // num0start + 0 + num1end
    int pf = 0, sf = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') ++pf;
        else break;
    }
    for (int i = n-1; i >= 0; --i) {
        if (s[i] == '1') ++sf;
        else break;
    }
    if (pf + sf == n)
        cout << s << "\n";
    else
        cout << string(pf, '0')+"0"+string(sf, '1') << "\n";
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

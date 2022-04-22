#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    string s;
    cin >> s;
    n = s.size();
    char a = 'z';
    for (auto c : s)
        a = min(a, c);
    cout << a << " ";
    string b;
    for (int i = 0; i < n; i++) {
        if (s[i] == a) {
            b += s.substr(0, i); 
            b += s.substr(i+1, n-i-1);
            break;
        }
    }
    cout << b << "\n";
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

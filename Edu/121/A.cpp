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
    vector<int> cnt(26, 0);
    for (char c : s)
        cnt[c-'a']++;
    string a, b;
    for (char c : s) {
        if (cnt[c-'a'] == 2) {
            a += c;
            cnt[c-'a'] = -1;
        } else if (cnt[c-'a'] != -1)
            b += c;
    }
    string d = a;
    cout << a + b + d << "\n";
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

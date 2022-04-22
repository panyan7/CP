#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    string s;
    cin >> s;
    bool diff = false;
    ll i = 0;
    while (i < s.size() && s[i] == s[0]) {
        i++;
    }
    if (i == s.size()) {
        cout << n << "\n";
        return;
    }
    ll w = 0, h = 0;
    for (int j = i; j < s.size(); j++) {
        if (s[j] == 'R')
            w++;
        else
            h++;
    }
    //cout << w << " " << h << "\n";
    cout << n * n - n * i - w * h + i << "\n";
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

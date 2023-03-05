#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    string res;
    for (int i = 0; i < 2*n-2; i++) {
        string s;
        cin >> s;
        if (s.size() == n/2)
            res += s;
    }
    bool ok = true;
    for (int i = 0; 2*i < res.size(); i++) {
        if (res[i] != res[res.size()-1-i])
            ok = false;
    }
    cout << (ok ? "YES\n" : "NO\n");
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

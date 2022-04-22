#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    ll x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    int i = n-1;
    x--;
    string res;
    while (i >= 0) {
        if (s[i] == 'a') {
            res = 'a' + res; 
            i--;
            continue;
        }
        int j = i;
        while (j >= 0 && s[j] == '*')
            j--;
        int cnt = (i-j) * k + 1;
        ll r = x % cnt;
        res = string(r, 'b') + res;
        x = x / cnt;
        i = j;
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

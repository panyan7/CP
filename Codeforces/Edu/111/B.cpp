#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    // check long long
    int a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int res = 0;
    if (b > 0) {
        res = n * (a + b);
    } else {
        int c = 0, d = 0;
        int l = 0;
        while (l < n) {
            int r = l;
            while (r < n && s[r] == s[l])
                r++;
            if (s[l] == '0')
                c++;
            else
                d++;
            l = r;
        }
        res = n * a + (min(c, d) + 1) * b;
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

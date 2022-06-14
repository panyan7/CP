#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    string s;
    int x;
    cin >> s >> x;
    int h = (s[0]-'0') * 10 + (s[1]-'0');
    int m = (s[3]-'0') * 10 + (s[4]-'0');
    int h_old = h, m_old = m;
    int res = 0;
    while (true) {
        if (h / 10 == (m % 10) && m / 10 == (h % 10))
            res++;
        m += x;
        h += (m / 60);
        m %= 60;
        h %= 24;
        if (h == h_old && m == m_old)
            break;
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

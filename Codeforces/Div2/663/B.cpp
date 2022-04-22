#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()
#define F_OR1(n) for (int i = 0; i < n; ++i)
#define F_OR2(i, n) for (int i = 0; i < n; ++i)
#define F_OR3(i, k, n) for (int i = k; i < n; ++i)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define F_OR(...) GET_MACRO(__VA_ARGS__, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_OR(__VA_ARGS__) (__VA_ARGS__)
#define EACH(x, a) for (auto& x : a)
const int MOD = 1e9+7;

int t, n, m;
char a[101][101];

void solve() {
    cin >> n >> m;
    FOR(n)
        cin >> a[i];
    int res = 0;
    FOR(n-1)
        if (a[i][m-1] != 'D')
            ++res;
    FOR(j, m-1)
        if (a[n-1][j] != 'R')
            ++res;
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

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
#define END(n) (i == n-1 ? "\n" : " ")
const int MOD = 1e9+7;

int t, n;

void solve() {
    cin >> n;
    FOR(n) {
        cout << i+1 << END(n);
    }
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

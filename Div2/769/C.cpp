#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    int a, b;
    cin >> a >> b;
    int res = INT_MAX;
    for (int i = 0; i <= b; i++) {
        int cur = (a | (b+i)) - (b+i) + i;
        if ((a | (b+i)) != a)
            cur++;
        res = min(res, cur);
    }
    for (int i = 0; i <= b; i++) {
        int cur = (b | (a+i)) - b + i;
        if ((b | (a+i)) != (a+i))
            cur++;
        res = min(res, cur);
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

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int res = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            res++;
            if (i > 0 && a[i-1] == 1)
                res += 4;
        }
        if (i > 0 && a[i] == 0 && a[i-1] == 0) {
            cout << "-1\n";
            return;
        }
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

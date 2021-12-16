#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    // check long long
    cin >> n;
    vector<int> a(2 * n);
    int cnt = 0;
    for (auto &x : a) {
        cin >> x;
        if (x % 2 == 1)
            cnt++;
    }
    if (cnt == n)
        cout << "Yes\n";
    else
        cout << "No\n";
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

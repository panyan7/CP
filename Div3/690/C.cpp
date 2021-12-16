#include <bits/stdc++.h>
using namespace std;

int t, x;

void solve() {
    if (x > 45) { cout << -1 << "\n"; return; }
    vector<int> res;
    for (int i = 9; i >= 1; --i) {
        if (x > i) res.push_back(i);
        else {
            res.push_back(x);
            break;
        }
        x -= i;
    }
    for (int i = res.size() - 1; i >= 0; --i) cout << res[i];
    cout << "\n";
}

int main() {
    cin >> t;
    while (t--) {
        cin >> x;
        solve();
    }
}

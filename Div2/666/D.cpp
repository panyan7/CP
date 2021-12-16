#include <bits/stdc++.h>
using namespace std;

int t, n;

void solve() {
    cin >> n;
    int mx = 0, sm = 0;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        sm += temp;
        mx = max(mx, temp);
    }
    if ((sm & 1) || (mx > sm-mx))
        cout << "T\n";
    else
        cout << "HL\n";
    return;
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

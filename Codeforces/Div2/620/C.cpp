#include <bits/stdc++.h>
using namespace std;

int q, n, m;
vector<int> t, l, h;
void solve() {
    int cl = m, ch = m, ct = 0;
    for (int i = 0; i < n; ++i) {
        int dt = t[i] - ct;
        if (l[i] > ch + dt || h[i] < cl - dt) {
            cout << "NO\n";
            return;
        }
        cl = max(l[i], cl-dt);
        ch = min(h[i], ch+dt);
        ct = t[i];
        assert(cl <= ch);
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while (q--) {
        cin >> n >> m;
        t.assign(n+1, 0);
        l.assign(n+1, 0);
        h.assign(n+1, 0);
        for (int i = 0; i < n; ++i)
            cin >> t[i] >> l[i] >> h[i];
        solve();
    }
    return 0;
}

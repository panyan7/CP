#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t, n, m, k;

bool cmp(const array<int,3>& a, const array<int,3>& b) {
    return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
}

void solve() {
    cin >> n;
    vector<array<int, 3>> f (0);
    for (int i = 0; i < n; ++i) {
        int h, w;
        cin >> h >> w;
        f.push_back({w, h, i});
        f.push_back({h, w, i});
    }
    sort(f.begin(), f.end(), cmp);
    int mn = INT_MAX, id = -1;
    vector<int> res (n, 0);
    for (int i = 0; i < f.size(); ++i) {
        if (f[i][1] > mn) res[f[i][2]] = id+1;
        else res[f[i][2]] = -1;
        if (f[i][1] < mn) mn = f[i][1], id = f[i][2];
    }
    for (auto& x : res) cout << x << " ";
    cout << "\n";
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

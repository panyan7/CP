#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int res = 0;
    vector<pii> c;
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && a[j] == a[i])
            ++j;
        c.push_back({a[i], j-i});
        i = j;
    }
    i = 0;
    int lst = -1;
    int l1 = -1, l2 = -1, n1 = 0, n2 = 0;
    int l3 = -1, n3 = 0;
    vector<int> lastid(n, -1);
    for (int i = 0; i < n; ++i) {
        if (lastid != )
        if (a[i] == l1) {
            ++n1;
        } else if (a[i] == l2) {
            ++n2;
        } else if (a[i] == l3) {
            ++n3;
        } else {

        }
    }
    cout << n1 + n2 << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

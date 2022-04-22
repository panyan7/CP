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
    while (i < c.size()) {
        while (i < c.size() && c[i].second > 1) {
            res += 2;
            lst = c[i].first;
            ++i;
        }
        if (i == c.size())
            break;
        int j = i;
        set<int> s;
        while (j < c.size() && c[j].second == 1) {
            s.insert(c[j].first);
            ++j;
        }
        if (j == c.size()) {
            res += j-i;
        } else {
            bool can = false;
            if (c[j].first == lst) {
                for (int l = i; l < j; ++l) {
                    if (c[l].first != lst && c[l-1].first != c[l+1].first) {
                        can = true;
                        break;
                    }
                }
                res += (can ? j-i : j-i-1);
            } else {
                res += j-i;
            }
        }
        i = j;
    }
    cout << res << "\n";
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

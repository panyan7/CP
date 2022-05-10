#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n >> k;
    map<int,int> mp;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        mp[b[i]]++;
    }
    vector<pii> a;
    for (auto& p : mp)
        a.push_back(p);
    n = a.size();
    int i = 0, j = 0, res = 0, start = 0;
    for (i = 0; i < n; i++) {
        if (a[i].second < k)
            continue;
        j = max(i+1, j);
        while (j < n && a[j].first == a[j-1].first + 1 && a[j].second >= k) {
            j++;
        }
        if (j-i > res) {
            res = max(res, j-i);
            start = a[i].first;
        }
    }
    if (res == 0)
        cout << "-1\n";
    else
        cout << start << " " << res+start-1 << "\n";
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

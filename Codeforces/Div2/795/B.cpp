#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    map<int,vector<int>> cnt;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cnt[a[i]].push_back(i);
    vector<int> res(n, 0);
    for (auto& p : cnt) {
        if (p.second.size() == 1) {
            cout << "-1\n";
            return;
        } else {
            res[p.second[0]] = p.second.back();
            for (int i = 1; i < p.second.size(); i++) {
                res[p.second[i]] = p.second[i-1];
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << res[i]+1 << " ";
    cout << "\n";
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

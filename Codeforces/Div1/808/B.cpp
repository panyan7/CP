#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int,int> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]]++;
    while (mp.size() > 1 || mp.begin()->second > 1) {
        vector<int> b;
        int zero = 0;
        for (auto p : mp) {
            if (p.second > 1)
                zero += (p.second - 1);
            b.push_back(p.first);
        }
        mp.clear();
        for (int i = 1; i < b.size(); i++) {
            mp[b[i] - b[i-1]]++;
        }
        if (zero)
            mp[0] = zero;
    }
    cout << mp.begin()->first << "\n";
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

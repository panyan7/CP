#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a)
        cin >> x;
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    int cnt = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (mp.find(a[i]) != mp.end()) {
            cout << "YES\n";
            return;
        }
        mp[a[i]] = i;
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        if (mp[b[i]] != i) {
            swap(a[i], a[mp[b[i]]]);
            mp[a[mp[b[i]]]] = mp[b[i]];
            mp[b[i]] = i;
            cnt++;
        }
    }
    cout << (cnt % 2 == 0 ? "YES\n" : "NO\n");
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

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<int> q(n);
    for (auto& x : q)
        cin >> x;
    string s;
    cin >> s;
    vector<array<int,3>> p;
    for (int i = 0; i < n; i++)
        p.push_back({s[i]-'0', q[i], i});
    sort(p.begin(), p.end());
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[p[i][2]] = i+1;
    for (int i = 0; i < n; i++)
        cout << res[i] << " \n"[i+1==n];
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

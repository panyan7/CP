#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    vector<int> b;
    b.push_back(a[0]);
    for (int i = 1; i < n; i++)
        if (a[i] != a[i-1])
            b.push_back(a[i]);
    int cnt = 0;
    if (b.size() <= 1) {
        cout << "YES\n";
        return;
    }
    if (b[0] < b[1])
        cnt++;
    if (b[b.size()-1] < b[b.size()-2])
        cnt++;
    for (int i = 1; i+1 < b.size(); i++) {
        if (b[i] < b[i-1] && b[i] < b[i+1])
            cnt++;
    }
    cout << (cnt == 1 ? "YES\n" : "NO\n");
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

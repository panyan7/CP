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
    sort(a.begin(), a.end());
    if (a[0] == a.back()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << a.back() << " ";
    for (int i = 0; i+1 < n; i++)
        cout << a[i] << " ";
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

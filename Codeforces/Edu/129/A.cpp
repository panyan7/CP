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
    cin >> m;
    vector<int> b(m);
    for (auto& x : b)
        cin >> x;
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    if (a[0] == b[0]) {
        cout << "Alice\n";
        cout << "Bob\n";
    } else if (a[0] > b[0]) {
        cout << "Alice\n";
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
        cout << "Bob\n";
    }
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

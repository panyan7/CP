#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    bool can = true;
    int i = 0;
    for (int j = 0; j < n; j++) {
        if (!(a[(i+j)%n] == b[j] || a[(i+j)%n]+1 == b[j])) {
            can = false;
            break;
        }
    }
    if (can) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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

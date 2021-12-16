#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    cin >> n;
    vector<ll> b(n+2);
    for (auto& x : b)
        cin >> x;
    sort(b.begin(), b.end());
    ll sum = 0;
    for (int i = 0; i <= n; i++)
        sum += b[i];
    for (int i = 0; i <= n; i++) {
        if (sum - b[i] == b[n+1]) {
            for (int j = 0; j <= n; j++) {
                if (j != i)
                    cout << b[j] << " ";
            }
            cout << "\n";
            return;
        }
    }
    if (sum - b[n] == b[n]) {
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";
        cout << "\n";
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

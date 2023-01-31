#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x % 2)
            odd.push_back(i+1);
        else
            even.push_back(i+1);
    }
    if (odd.size() >= 3) {
        cout << "YES\n" << odd[0] << " " << odd[1] << " " << odd[2] << "\n";
    } else if (odd.size() >= 1 && even.size() >= 2) {
        cout << "YES\n" << odd[0] << " " << even[0] << " " << even[1] << "\n";
    } else {
        cout << "NO\n";
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

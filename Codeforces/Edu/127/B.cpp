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
    int cnt2 = 0, cnt3 = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i-1] > 3) {
            cout << "NO\n";
            return;
        } else if (a[i] - a[i-1] == 2) {
            cnt2++;
        } else if (a[i] - a[i-1] == 3) {
            cnt3++;
        }
    }
    if ((cnt2 <= 2 && cnt3 == 0) || (cnt3 == 1 && cnt2 == 0))
        cout << "YES\n";
    else
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

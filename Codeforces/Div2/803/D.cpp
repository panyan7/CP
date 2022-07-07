#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    int l = 0, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        // [l, mid)
        cout << "? " << mid+1 << " " << r << "\n";
        cout.flush();
        int cnt = 0;
        for (int i = mid+1; i <= r; i++) {
            int x; cin >> x;
            if (x >= mid+1 && x <= r)
                cnt++;
        }
        if (cnt % 2 == 1)
            l = mid + 1;
        else
            r = mid;
    }
    cout << "! " << l << "\n";
    cout.flush();
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

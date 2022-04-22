#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    int x;
    cin >> n;
    int lo = 1, hi = n;
    int c = 0;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        // (mid + c + q) % n == 0
        int q = n - (mid + c) % n;
        cout << "+ " << q << "\n";
        cout.flush();
        int d;
        cin >> d;
        if (d == (mid + c + q) / n)
            lo = mid;
        else
            hi = mid;
        c += q;
    }
    cout << "! " << lo + c << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n);
    int lo = 1, hi = n;
    const int NUM = 10;
    while (lo <= hi) {
        if (hi-lo-1 <= NUM) {
            int mn = INT_MAX, mnid;
            for (int i = lo; i <= hi; ++i) {
                cout << "? " << i << "\n";
                cout.flush();
                cin >> a[i-1];
                if (a[i-1] < mn){
                    mn = a[i-1];
                    mnid = i;
                }
            }
            cout << "! " << mnid << "\n";
            return;
        }
        int mn = INT_MAX, mnid;
        for (int i = 0; i <= NUM; ++i) {
            int id = lo + (hi-lo)*i/NUM;
            cout << "? " << id << "\n";
            cout.flush();
            cin >> a[id-1];
            if (a[id-1] < mn) {
                mn = a[id-1];
                mnid = i;
            }
        }
        if (mnid > 0)
            lo = lo + (hi-lo) * (mnid-1) / NUM;
        if (mnid < NUM)
        hi = lo + (hi-lo) * (mnid+1) / NUM;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

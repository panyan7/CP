#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    int cnt;
    cin >> cnt;
    int n = 0, cur = 0;
    for (int i = 0; i < 30; i++) {
        cout << "- " << (1 << max(i-1,0)) << "\n";
        cout.flush();
        int cnt_new;
        cin >> cnt_new;
        if (cnt_new < cnt) {
            n |= (1 << i);
            cur++;
        }
        if (cur == cnt) {
            cout << "! " << n << "\n";
            cout.flush();
            return;
        }
    }
    cout << "! " << n << "\n";
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

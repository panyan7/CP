#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> res;
    if (n % 2 == 1) {
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = i+1; j < n; ++j) {
                if (cnt < n/2) {
                    res.push_back(1);
                    ++cnt;
                } else {
                    res.push_back(-1);
                }
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = i+1; j < n; ++j) {
                if (cnt < n/2-1) {
                    res.push_back(1);
                    ++cnt;
                } else if (cnt == n/2-1) {
                    res.push_back(0);
                    ++cnt;
                } else {
                    res.push_back(-1);
                }
            }
        }
    }
    for (int x : res)
        cout << x << " ";
    cout << "\n";
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

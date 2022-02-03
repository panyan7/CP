#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<int> res;
    int cur = 1;
    while (true) {
        if (n == 0)
            break;
        for (int i = 0; i < (n+1)/2; i++)
            res.push_back(cur);
        if (n == 3) {
            cur *= 3;
            n = 1;
        } else {
            cur *= 2;
            n -= (n+1)/2;
        }
    }
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << "\n";
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

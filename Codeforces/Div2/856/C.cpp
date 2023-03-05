#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> s(n);
    for (auto& x : s)
        cin >> x;
    vector<int> res(n);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j <= i && s[j] < i-j+1)
            j++;
        res[i] = i-j+1;
    }
    for (auto x : res)
        cout << x << " ";
    cout << "\n";
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

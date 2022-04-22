#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (s[i] > res.size())
            res.push_back(s[i]);
    }
    cout << res.size() << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    for (int t1 = 1; t1 <= tt; t1++) {
        cout << "Case #" << t1 << ": ";
        solve();
    }
    return 0;
}

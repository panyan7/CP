#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
 
int t = 1, n, m, k;
 
void solve() {
    // check long long
    cin >> n;
    string s;
    vector<vector<int>> a(5, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        cin >> s;
        vector<int> b(5, 0);
        for (char c : s) {
            b[c-'a']++;
        }
        for (int j = 0; j < 5; j++) {
            a[j][i] = 2 * b[j] - s.size();
        }
    }
    int res = 0;
    for (int j = 0; j < 5; j++) {
        int cur = 0, i = 0;
        sort(a[j].begin(), a[j].end(), greater<int>());
        for (i = 0; i < n; i++) {
            if (cur + a[j][i] > 0) {
                cur += a[j][i];
            } else {
                break;
            }
        }
        res = max(res, i);
    }
    cout << res << "\n";
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

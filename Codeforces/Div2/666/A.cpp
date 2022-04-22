#include <bits/stdc++.h>
using namespace std;
int t, n;
vector<int> cnt (26, 0);

void solve() {
    cin >> n;
    cnt.assign(26, 0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            cnt[c-'a']++;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] % n) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

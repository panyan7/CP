#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(10, 0);
    for (char c : s)
        cnt[c-'0']++;
    int mx = *max_element(cnt.begin(), cnt.end());
    if (mx == 4)
        cout << "-1\n";
    else if (mx == 3)
        cout << "6\n";
    else
        cout << "4\n";
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

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m, k;

vector<int> steps(const vector<int>& a) {
    vector<int> res;
    for (int i = 0; i < n-1; ++i)
        if (a[i] && !a[i+1])
            res.push_back(i);
    return res;
}

void solve() {
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a (n, 0);
    for (int i = 0; i < n; ++i)
        a[i] = int(s[i] != 'L');
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

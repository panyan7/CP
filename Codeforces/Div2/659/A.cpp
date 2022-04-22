#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m;

void solve() {
    cin >> n;
    vector<int> a (n);
    for (auto& x : a)
        cin >> x;
    string out;
    for (int i = 0; i < 50; ++i) {
        out += 'a';
    }
    cout << out << "\n";
    for (int i = 0; i < n; ++i) {
        if (a[i] < 50) {
            if (out[a[i]] < 'z')
                out[a[i]] += 1;
            else
                out[a[i]] -= 25;
        }
        cout << out << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

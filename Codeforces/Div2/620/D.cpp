#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;
void solve() {
    int c = n, l = 0;
    vector<int> out (n, 0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '>' || i == n-1) {
            for (int j = i; j >= l; --j) {
                out[j] = c--;
            }
            l = i+1;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << out[i] << (i == n-1 ? "\n" : " ");
    out.assign(n, 0);
    c = 1; l = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '<' || i == n-1) {
            for (int j = i; j >= l; --j) {
                out[j] = c++;
            }
            l = i+1;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << out[i] << (i == n-1 ? "\n" : " ");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        solve();
    }
    return 0;
}

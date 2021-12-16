#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    cin >> n;
    vector<string> s(n);
    int cnt = 0;
    array<int,2> x, y;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '*') {
                x[cnt] = i;
                y[cnt] = j;
                cnt++;
            }
        }
    }
    if (x[0] == x[1]) {
        int nx = (x[0] + 1) % n;
        s[nx][y[0]] = '*';
        s[nx][y[1]] = '*';
    } else if (y[0] == y[1]) {
        int ny = (y[0] + 1) % n;
        s[x[0]][ny] = '*';
        s[x[1]][ny] = '*';
    } else {
        s[x[0]][y[1]] = '*';
        s[x[1]][y[0]] = '*';
    }
    for (int i = 0; i < n; i++) {
        cout << s[i] << "\n";
    }
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

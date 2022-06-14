#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
string board[8];

void solve() {
    for (int i = 0; i < 8; i++)
        cin >> board[i];
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 7; j++) {
            if (board[i][j] == '#' && board[i-1][j-1] == '#' && board[i-1][j+1] == '#' && board[i+1][j-1] == '#' && board[i+1][j+1] == '#') {
                cout << i+1 << " " << j+1 << "\n";
                return;
            }
        }
    }
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

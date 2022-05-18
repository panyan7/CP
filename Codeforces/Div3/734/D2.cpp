#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
 
int t = 1, n, m, k;
 
void solve() {
    // check long long
    cin >> n >> m >> k;
    bool swapped = false;
    if (m % 2 == 1) {
        k = (m * n) / 2 - k;
        swap(m, n);
        swapped = true;
    }
    // only n can be odd
    bool can = true;
    int min_h = (n % 2) * (m / 2);
    if (k < min_h)
        can = false;
    if ((k - min_h) % 2 != 0)
        can = false;
    if (!can) {
        cout << "NO\n";
        return;
    } else {
        cout << "YES\n";
        vector<vector<char>> board(n, vector<char>(m, 0));
        if (n % 2 == 1) {
            for (int j = 0; j < m; j++) {
                board[n-1][j] = ((j/2) % 2) ? 'y' : 'z';
            }
            k -= m/2;
        }
        for (int i = 0; i+1 < n; i += 2) {
            for (int j = 0; j+1 < m; j += 2) {
                char a, b;
                if ((i/2 + j/2) % 2 == 0)
                    a = 'a', b = 'b';
                else
                    a = 'c', b = 'd';
                if (k > 0) {
                    board[i][j] = a;
                    board[i][j+1] = a;
                    board[i+1][j] = b;
                    board[i+1][j+1] = b;
                    k -= 2;
                } else {
                    board[i][j] = a;
                    board[i][j+1] = b;
                    board[i+1][j] = a;
                    board[i+1][j+1] = b;
                }
            }
        }
        if (swapped) {
            for (int j = 0; j < m; j++) {
                for (int i = 0; i < n; i++) {
                    cout << board[i][j];
                }
                cout << "\n";
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << board[i][j];
                }
                cout << "\n";
            }
        }
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

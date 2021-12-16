#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m;

void solve() {
    cin >> n;
    if (n < 3) { cout << -1 << "\n"; return; }
    vector<vector<int>> sol3 = {{9,5,6},{7,2,8},{1,3,4}};
    vector<vector<int>> sol4 = {{11,10,8,7},{15,9,14,6},
                                {13,12,16,5},{1,2,3,4}};
    vector<vector<int>> sol (n, vector<int> (n, 0));
    if (n % 2 == 1) {
        int d = n*n - 9, o = (n-3)/2;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                sol[i+o][j+o] = sol3[i][j] + d;
            }
        }
        int c = 1;
        for (int i = 0; i < o; ++i) {
            for (int j = i; j < n-i-1; ++j) {
                sol[n-i-1][j] = c;
                ++c;
            }
            for (int j = n-i-1; j > i; --j) {
                sol[j][n-i-1] = c;
                ++c;
            }
            for (int j = n-i-1; j > i; --j) {
                sol[i][j] = c;
                ++c;
            }
            for (int j = i; j < n-i-1; ++j) {
                sol[j][i] = c;
                ++c;
            }
        }
    } else {
        int d = n*n - 16, o = (n-4)/2;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                sol[i+o][j+o] = sol4[i][j] + d;
            }
        }
        int c = 1;
        for (int i = 0; i < o; ++i) {
            for (int j = i; j < n-i-1; ++j) {
                sol[n-i-1][j] = c;
                ++c;
            }
            for (int j = n-i-1; j > i; --j) {
                sol[j][n-i-1] = c;
                ++c;
            }
            for (int j = n-i-1; j > i; --j) {
                sol[i][j] = c;
                ++c;
            }
            for (int j = i; j < n-i-1; ++j) {
                sol[j][i] = c;
                ++c;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << sol[i][j] << (j == n-1 ? "\n" : " ");
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

// Undecidable
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> p(2, vector<int>(1000001, -1));
vector<vector<pair<bool, int>>> a(2);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s[2];
    getline(cin, s[0]); getline(cin, s[1]);
    // cout << "?";
    // return 0;
    for (int i = 0; i < 2; i++) {
        int sz = s[i].size();
        int j = 0;
        while (j < sz) {
            // cout << j << ' ';
            if (s[i][j] == ' ') {
                j++;
                continue;
            }
            if (s[i][j] == '(') {
                a[i].push_back({false, 1});
                j++;
                continue;
            }
            if (s[i][j] == ')') {
                a[i].push_back({false, -1});
                j++;
                continue;
            }
            int num = 0;
            while (j < sz && s[i][j] <= '9' && s[i][j] >= '0') {
                num = num * 10 + (s[i][j] - '0');
                j++;
            }
            a[i].push_back({true, num});
        }
        
    }
    // cout << "??";
    // for (auto i : a[1]) cout << i.first << ' ' << i.second << '\n';
    // return 0;
    function<void(int, int, int, int)> dfs = [&](int i, int j, int ind, int pa) {
            // cout << i << ' ' << j << endl;
            int cur = a[ind][i].second;
            p[ind][cur] = pa;
            int pos = i + 1;
            while (pos < j) {
                int end = pos;
                int tot = 0;
                while (true) {
                    // cout << end << endl;
                    if (!a[ind][end].first) tot += a[ind][end].second;
                    end++;
                    // cout << end << ' ' << tot << '\n';
                    if (tot == 0) break;
                }
                // cout << pa << ' ' << cur << endl;
                // cout << pos << ' ' << end << endl;
                dfs(pos + 1, end - 2, ind, cur);
                pos = end;
            }
        };
        for (int i = 0; i < 2; i++) dfs(0, a[i].size(), i, 0);
    // for (int i = 10; i <= 12; i++) cout << p[0][i] << ' ' << p[1][i] << '\n';
    for (int i = 1; i <= 1000000; i++) {
        if (p[0][i] != p[1][i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}


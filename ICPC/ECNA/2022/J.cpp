// Undecidable
#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> a, cur;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N = 52;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        a.push_back({s[0], s[1]});
    }
    for (int i = 0; i < N; i++) {
        cur.push_back(a[i]);
        while (true) {
            int cur_status = 0, pos = -1;
            int sz = cur.size();
            // cout << sz << '\n';
            for (int j = sz - 1; j >= 3; j--) {
                if (cur[j][1] == cur[j - 3][1] && cur_status == 0) {
                    cur_status = 1;
                    pos = j;
                }
                if (cur[j][0] == cur[j - 3][0]) {
                    cur_status = 2;
                    pos = j;
                    break;
                }
            }
            if (cur_status == 0) break;
            set<int> tmp;
            if (cur_status == 1) {
                tmp.insert(pos);
                tmp.insert(pos - 3);
            }
            else {
                for (int j = pos - 3; j <= pos; j++) tmp.insert(j);
            }
            vector<vector<char>> T;
            for (int i = 0; i < sz; i++) {
                if (!tmp.count(i)) T.push_back(cur[i]);
            }
            swap(T, cur);
        }
    }
    cout << cur.size() << ' ';
    for (auto j : cur) {
        cout << j[0] << j[1] << ' ';
    }
}


#include <bits/stdc++.h>
using namespace std;
#define ll long long

string b[105];
int tr[105][105], wa[105][105];
char res[105][105];
int n, m;
string labels;

bool check(int r, int c, int sz, int& tr_cnt) {
    if (r+sz-1 >= n || c+sz-1 >= m)
        return false;
    for (int i = r; i < r+sz; i++) {
        switch (res[i][c+sz-1]) {
        case '$':
            tr_cnt++;
            if (tr_cnt > 1)
                return false;
        case '.':
            break;
        default:
            return false;
        }
    }
    for (int i = c; i < c+sz-1; i++) {
        switch (res[r+sz-1][i]) {
        case '$':
            tr_cnt++;
            if (tr_cnt > 1)
                return false;
        case '.':
            break;
        default:
            return false;
        }
    }
    return true;
}

void fill_res(int r, int c, int sz, int idx) {
    for (int i = r; i < r+sz; i++)
        res[i][c+sz-1] = labels[idx];
    for (int i = c; i < c+sz-1; i++)
        res[r+sz-1][i] = labels[idx];
}

void unfill_res(int r, int c, int sz) {
    for (int i = r; i < r+sz; i++)
        for (int j = c; j < c+sz; j++)
            res[i][j] = b[i][j];
}

bool search(int r, int c, int idx) {
    while (r < n) {
        while (c < m && res[r][c] != '.' && res[r][c] != '$') {
            c++;
        }
        if (c < m)
            break;
        r++; c = 0;
    }
    if (r == n)
        return true;
    int tr_cnt = 0;
    int sz = 1;
    for (sz = 1; r+sz <= n && c+sz <= m; sz++) {
        bool ck = check(r, c, sz, tr_cnt);
        if (!ck) {
            unfill_res(r, c, sz-1);
            break;
        } else if (tr_cnt == 0) {
            fill_res(r, c, sz, idx);
        } else {
            fill_res(r, c, sz, idx);
            bool nxt = search(r, c, idx+1);
            if (nxt)
                return true;
        }
    }
    unfill_res(r, c, sz-1);
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 26; i++)
        labels.push_back('A' + i);
    for (int i = 0; i < 26; i++)
        labels.push_back('a' + i);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[i][j] = b[i][j];
    bool ans = search(0, 0, 0);
    if (ans) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << res[i][j];
            cout << "\n";
        }
    } else {
        cout << "elgnatcer\n";
    }
    return 0;
}

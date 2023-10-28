#include <bits/stdc++.h>
using namespace std;
 
using mat = array<array<int,9>,9>;
bool row_rem[9][10], col_rem[9][10], sub_rem[3][3][10];
 
bool check(mat& a, int x, int y, int n) {
    if (a[x][y] != 0)
        return false;
    return (row_rem[x][n] && col_rem[y][n] && sub_rem[x/3][y/3][n]);
}
 
int unique_location_rule(mat& a) {
    int found = 0;
    for (int i = 0; i < 9; i++) {
        for (int n = 1; n <= 9; n++) {
            int loc = -1, cnt = 0;
            if (!row_rem[i][n])
                continue;
            for (int j = 0; j < 9; j++) {
                if (check(a, i, j, n)) {
                    loc = j;
                    cnt++;
                }
            }
            if (cnt == 1) {
                a[i][loc] = n;
                row_rem[i][n] = false;
                col_rem[loc][n] = false;
                sub_rem[i/3][loc/3][n] = false;
                found++;
            }
        }
        for (int n = 1; n <= 9; n++) {
            int loc = -1, cnt = 0;
            if (!col_rem[i][n])
                continue;
            for (int j = 0; j < 9; j++) {
                if (check(a, j, i, n)) {
                    loc = j;
                    cnt++;
                }
            }
            if (cnt == 1) {
                a[loc][i] = n;
                row_rem[loc][n] = false;
                col_rem[i][n] = false;
                sub_rem[loc/3][i/3][n] = false;
                found++;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int n = 1; n <= 9; n++) {
                int lx = 0, ly = 0, cnt = 0;
                if (!sub_rem[i][j][n])
                    continue;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (check(a, i*3+k, j*3+l, n)) {
                            lx = i*3+k, ly = j*3+l;
                            cnt++;
                        }
                    }
                }
                if (cnt == 1) {
                    a[lx][ly] = n;
                    row_rem[lx][n] = false;
                    col_rem[ly][n] = false;
                    sub_rem[lx/3][ly/3][n] = false;
                    found++;
                }
            }
        }
    }
    return found;
};
 
int single_value_rule(mat& a) {
    int found = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (a[i][j] != 0)
                continue;
            vector<bool> ok(10, 1);
            for (int n = 1; n <= 9; n++) {
                if (!row_rem[i][n])
                    ok[n] = false;
                if (!col_rem[j][n])
                    ok[n] = false;
                if (!sub_rem[i/3][j/3][n])
                    ok[n] = false;
            }
            int sol = 0, cnt = 0;
            for (int n = 1; n <= 9; n++) {
                if (ok[n]) {
                    sol = n; cnt++;
                }
            }
            if (cnt == 1) {
                a[i][j] = sol;
                row_rem[i][sol] = false;
                col_rem[j][sol] = false;
                sub_rem[i/3][j/3][sol] = false;
                found++;
            }
        }
    }
    return found;
}
 
void print_mat(mat& a) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (a[i][j] == 0)
                cout << ". ";
            else
                cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    mat a;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> a[i][j];
    memset(row_rem, 1, sizeof(row_rem));
    memset(col_rem, 1, sizeof(col_rem));
    memset(sub_rem, 1, sizeof(sub_rem));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (a[i][j] == 0)
                continue;
            row_rem[i][a[i][j]] = false;
            col_rem[j][a[i][j]] = false;
            sub_rem[i/3][j/3][a[i][j]] = false;
        }
    }
    while (true) {
        int r1 = single_value_rule(a);
        int r2 = unique_location_rule(a);
        if (!r1 && !r2) {
            break;
        }
    }
    int cnt = 0;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (a[i][j] == 0)
                cnt++;
    if (cnt)
        cout << "Not easy\n";
    else
        cout << "Easy\n";
    print_mat(a);
    return 0;
}

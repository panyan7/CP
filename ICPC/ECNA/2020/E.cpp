#include "bits/stdc++.h"
using namespace std;
#define ll long long
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n; cin >> n;
    int mat[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    const int MOD = 37;
    auto char_to_int = [](char c) {
        if (c >= 'A' && c <= 'Z')
            return (int)(c-'A');
        if (c >= '0' && c <= '9')
            return (int)(c-'0')+26;
        return 36;
    };
    auto int_to_char = [](int x) {
        if (x < 26)
            return (char)('A' + x);
        if (x < 36)
            return (char)('0' + x-26);
        return ' ';
    };
 
    string s;
    getline(cin, s);
    getline(cin, s);
    vector<int> a;
    for (char c : s) {
        a.push_back(char_to_int(c));
    }
    while (a.size() % n != 0)
        a.push_back(char_to_int(' '));
    vector<int> b(a.size());
    for (int i = 0; i < a.size(); i++) {
        int k = (i / n);
        k *= n;
        for (int j = k; j < k + n; j++) {
            b[i] += mat[i%n][j-k] * a[j];
            b[i] %= MOD;
        }
    }
    string res;
    for (int x : b)
        res.push_back(int_to_char(x));
    cout << res << "\n";
 
    return 0;
}


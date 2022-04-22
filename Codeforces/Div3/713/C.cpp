#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    n = a + b;
    bool can = true;
    string res(n, '?');
    array<int,2> rem = {a, b};
    if (a % 2 == 1 && b % 2 == 1) {
        cout << "-1\n";
        return;
    } else if (a % 2 == 1) {
        if (s[n/2] == '1') {
            cout << "-1\n";
            return;
        }
        res[n/2] = '0';
        rem[0]--;
    } else if (b % 2 == 1) {
        if (s[n/2] == '0') {
            cout << "-1\n";
            return;
        }
        res[n/2] = '1';
        rem[1]--;
    }
    for (int i = 0; i < n/2; i++) {
        if (s[i] == s[n-i-1]) {
            res[i] = res[n-i-1] = s[i];
            if (s[i] != '?')
                rem[s[i]-'0'] -= 2;
        } else if (s[i] == '?') {
            res[i] = res[n-i-1] = s[n-i-1];
            rem[s[n-i-1]-'0'] -= 2;
        } else if (s[n-i-1] == '?') {
            res[i] = res[n-i-1] = s[i];
            rem[s[i]-'0'] -= 2;
        } else {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 0; i < n/2; i++) {
        if (res[i] == '?') {
            for (int j = 0; j < 2; j++) {
                if (rem[j] > 0) {
                    rem[j] -= 2;
                    res[i] = res[n-i-1] = j + '0';
                    break;
                }
            }
        }
    }
    if (rem[0] == 0 && rem[1] == 0)
        cout << res << "\n";
    else
        cout << "-1\n";
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

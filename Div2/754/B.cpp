#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    string s;
    cin >> s;
    int one = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            one++;
    }
    int cnt = 0;
    for (int i = 0; i < one; i++) {
        if (s[i] == '1')
            cnt++;
    }
    //cout << one << " ";
    if (cnt == 0)
        cout << "0\n";
    else {
        cout << "1\n";
        cout << cnt*2 << " ";
        for (int i = 0; i < one; i++) {
            if (s[i] == '1')
                cout << i+1 << " ";
        }
        for (int i = one; i < n; i++) {
            if (s[i] == '0')
                cout << i+1 << " ";
        }
        cout << "\n";
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

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    string s;
    cin >> s;
    n = s.size();
    int id = -1;
    for (int i = 1; i + 1 < n; i++) {
        if (s[i] == 'a')
            id = i;
    }
    if (id == -1) {
        cout << s[0] << " " << s.substr(1, n-2) << " " << s.back() << "\n";
    } else {
        cout << s.substr(0, id) << " " << s[id] << " " << s.substr(id+1, n-id-1) << "\n";
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

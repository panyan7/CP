#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    string a, b;
    cin >> a >> b;
    if (a[0] == b[0]) {
        cout << "YES\n";
        cout << string(1,a[0]) + "*\n";
        return;
    }
    if (a.back() == b.back()) {
        cout << "YES\n";
        cout << "*" + string(1,a.back()) + "\n";
        return;
    }
    set<string> st;
    for (int i = 0; i+1 < a.size(); i++) {
        st.insert(a.substr(i, 2));
    }
    for (int i = 0; i+1 < b.size(); i++) {
        if (st.count(b.substr(i, 2))) {
            cout << "YES\n";
            cout << "*" + b.substr(i, 2) + "*\n";
            return;
        }
    }
    cout << "NO\n";
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

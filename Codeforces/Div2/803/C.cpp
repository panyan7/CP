#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n <= 4) {
        set<int> st;
        for (int x : a)
            st.insert(x);
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    if (!st.count(a[i] + a[j] + a[k])) {
                        cout << "NO\n";
                        return;
                    }
                }
            }
        }
        cout << "YES\n";
        return;
    }
    vector<ll> b;
    for (int i = 0; i < n; i++)
        if (a[i] != 0)
            b.push_back(a[i]);
    if (b.size() <= 1)
        cout << "YES\n";
    else if (b.size() >= 3) {
        cout << "NO\n";
    } else {
        if (b[0] + b[1] == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
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

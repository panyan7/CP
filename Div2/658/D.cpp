#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<int> a(2*n);
    for (auto& x : a)
        cin >> x;
    int i = 0;
    vector<int> len;
    while (i < 2*n) {
        int j = i;
        while (j < 2*n && a[j] <= a[i])
            j++;
        len.push_back(j-i);
        i = j;
    }
    vector<bool> can(2*n+1, 0);
    can[0] = 1;
    for (int i = 0; i < (int)len.size(); i++) {
        for (int j = 2*n; j >= 0; j--) {
            if (can[j])
                can[j+len[i]] = true;
        }
    }
    cout << (can[n] ? "YES\n" : "NO\n");
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

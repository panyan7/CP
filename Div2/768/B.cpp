#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int i = n-1;
    int res = 0;
    while (i >= 0) {
        while (i >= 0 && a[i] == a[n-1])
            i--;
        if (i < 0)
            break;
        for (int j = i; j >= max(0, i-(n-1-i)+1); j--) {
            a[j] = a[n-1];
        }
        res++;
    }
    cout << res << "\n";
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

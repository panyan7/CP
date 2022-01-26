#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    vector<ll> a(1e7+1, 0), b(1e7+1, -1);
    for (int i = 1; i <= 1e7+1; i++) {
        for (int j = i; j <= 1e7; j += i) {
            a[j] += i;
        }
    }
    for (int i = 1; i <= 1e7+1; i++) {
        if (a[i] <= 1e7 && b[a[i]] == -1)
            b[a[i]] = i;
    }
    while (t--) {
        ll c; cin >> c;
        cout << b[c] << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        long long x = (1 << n) + (1 << (n/2)) - 2;
        long long y = (1 << (n+1)) - 2 - x;
        cout << (x-y) << "\n";
    }
    return 0;
}

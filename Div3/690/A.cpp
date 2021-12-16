#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> b (n);
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n/2; ++i) {
            cout << b[i] << " " << b[n-i-1] << " ";
        }
        if (n % 2) cout << b[n/2] << "\n";
        else cout << "\n";
    }
}

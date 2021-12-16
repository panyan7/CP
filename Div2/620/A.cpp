#include <bits/stdc++.h>
using namespace std;

int t, x, y, a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> x >> y >> a >> b;
        if ((y-x) % (a+b) == 0)
            cout << ((y-x) / (a+b)) << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}

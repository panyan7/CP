#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define PI 3.1415926535897

int t = 1, n, m, k;

void solve() {
    cin >> n;
    double theta = PI / (double)n;
    double r = (PI / 2.0 - (double)(n >> 1) * theta) / 2.0;
    double l = 1.0 / sin(theta / 2.0);
    cout << fixed << setprecision(10) << l * cos(r) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

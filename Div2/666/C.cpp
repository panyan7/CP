#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<ll> a;

int main() {
    cin >> n;
    a.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << "1 1\n" << -a[0] << "\n";
    if (n == 1) {
        cout << "1 1\n0\n1 1\n0\n";
        return 0;
    }
    cout << "2 " << n << "\n";
    for (int i = 1; i < n; ++i) {
        ll m = a[i] % n;
        cout << m * (n-1) << " ";
    }
    cout << "\n1 " << n << "\n0 ";
    for (int i = 1; i < n; ++i) {
        ll m = a[i] % n;
        cout << -(a[i] + m * (n-1)) << " ";
    }
    cout << "\n";
    return 0;
}

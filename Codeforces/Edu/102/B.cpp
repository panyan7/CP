#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m;

int gcd(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

void solve() {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int n1 = s1.size(), n2 = s2.size();
    int r1 = n2/gcd(n1,n2), r2 = n1/gcd(n1,n2);
    string a1, a2;
    for (int i = 0; i < r1; ++i) a1 += s1;
    for (int i = 0; i < r2; ++i) a2 += s2;
    if (a1 == a2) {
        cout << a1 << "\n";
    } else {
        cout << "-1\n";
    }
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

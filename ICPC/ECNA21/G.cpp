#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll powq[20];

pair<ll, ll> swap_two(ll a, ll b, ll na, ll nb, ll la, ll lb) {
    if (la == 0 || la >= na || lb == 0 || lb >= nb)
        return {a, b};
    ll ar = a % powq[na - la];
    ll br = b % powq[nb - lb];
    ll ak = a / powq[na - la];
    ll bk = b / powq[nb - lb];
    return {bk * powq[na - la] + ar, ak * powq[nb - lb] + br};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char op, eq;
    ll a, b, c;
    ll na = 0, nb = 0, nc = 0;
    cin >> a >> op >> b >> eq >> c;
    ll k = a;
    while (k > 0) {
        na++;
        k /= 10;
    }
    k = b;
    while (k > 0) {
        nb++;
        k /= 10;
    }
    k = c;
    while (k > 0) {
        nc++;
        k /= 10;
    }

    powq[0] = 1;
    for (int i = 1; i <= 10; i++) {
        powq[i] = powq[i-1] * 10;
    }

    bool ok = false;
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (op == '*') {
                pair<ll, ll> p = swap_two(a, b, na, nb, i, j);
                if (p.first * p.second == c) {
                    cout << p.first << " * " << p.second << " = " << c << "\n";
                    return 0;
                }
                p = swap_two(b, c, nb, nc, i, j);
                if (a * p.first == p.second) {
                    cout << a << " * " << p.first << " = " << p.second << "\n";
                    return 0;
                }
                p = swap_two(a, c, na, nc, i, j);
                if (p.first * b == p.second) {
                    cout << p.first << " * " << b << " = " << p.second << "\n";
                    return 0;
                }
            } else {
                pair<ll, ll> p = swap_two(a, b, na, nb, i, j);
                if (p.first + p.second == c) {
                    cout << p.first << " + " << p.second << " = " << c << "\n";
                    return 0;
                }
                p = swap_two(b, c, nb, nc, i, j);
                if (a + p.first == p.second) {
                    cout << a << " + " << p.first << " = " << p.second << "\n";
                    return 0;
                }
                p = swap_two(a, c, na, nc, i, j);
                if (p.first + b == p.second) {
                    cout << p.first << " + " << b << " = " << p.second << "\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}


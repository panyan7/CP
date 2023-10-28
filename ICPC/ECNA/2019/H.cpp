#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a/b * x, d;
}

ll crt(ll a, ll m, ll b, ll n) {
    if (n > m) swap(a, b), swap(m, n);
    ll x, y, g = euclid(m, n, x, y);
    assert((a - b) % g == 0); // else no solution
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m*n/g : x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    ll r[3];
    ll f, g;
    cin >> a >> b;
    for (int i = 0; i < 3; i++)
        cin >> r[i];
    cin >> f >> g;
    ll delta = 16 * (a + b) * (a + b) - 48 * a * b;
    set<ll> cand;
    cand.insert(1);
    cand.insert(2);
    cand.insert(3);
    cand.insert(4);
    cand.insert((a-1)/2);
    cand.insert((a-1)/2-1);
    cand.insert((a-1)/2-2);
    cand.insert((a-1)/2-3);
    if (delta >= 0) {
        double hstar = (4*(a+b) - sqrt((double)delta))/24.;
        cand.insert(floor(hstar-3));
        cand.insert(floor(hstar-2));
        cand.insert(floor(hstar-1));
        cand.insert(floor(hstar));
        cand.insert(floor(hstar+1));
        cand.insert(floor(hstar+2));
        cand.insert(floor(hstar+3));
        cand.insert(floor(hstar+4));
    }
    vector<ll> vols;
    for (ll x : cand) {
        if (x <= 0 || 2*x >= b)
            continue;
        ll vol = x * (a - 2*x) * (b - 2*x);
        vols.push_back(vol);
    }
    sort(vols.begin(), vols.end(), greater<>());
    vols.erase(unique(vols.begin(), vols.end()), vols.end());
    ll m[3];
    for (int i = 0; i < 3; i++) {
        m[i] = vols[i];
    }
    ll mm = lcm(m[0], m[1]);
    ll rr = crt(r[0], m[0], r[1], m[1]);
    rr = crt(rr, mm, r[2], m[2]);
    mm = lcm(mm, m[2]);
    ll k = (g - rr) / mm;
    cout << mm * k + rr << "\n";
    return 0;
}

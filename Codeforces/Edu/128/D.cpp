#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
ll a[3005], p[3005], nz[3005];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        p[i] = p[i-1] + a[i];
    ll sum_steps = -p[n];
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0)
            nz[i] = nz[i-1] + 1;
        else
            nz[i] = nz[i-1];
    }
    ll lo = 0, hi = 1e15;
    auto check = [&](ll lm) {
        for (int i = 1; i <= n; i++) { // leftmost
            if (lm > p[i])
                return true;
            if (p[i] - lm > nz[i] * k)
                continue;
            ll first_step = p[i] - lm;
            for (int j = i+1; j <= n; j++) { // rightmost
                // 1..i left (p[i] - lm), i+1..j right, j+1..n left
                ll last_step = (nz[n] - nz[j]) * k;
                ll this_step = sum_steps + last_step + first_step;
                if (this_step <= (nz[j] - nz[i]) * k)
                    return true;
            }
            for (int j = 1; j < i; j++) {

            }
        }
        return false;
    }
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

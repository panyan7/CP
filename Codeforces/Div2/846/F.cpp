#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;
const int N = 3e5;
int p[N+10], a[N+10];
int comp[N+10];
vector<int> primes;

void solve() {
    primes.push_back(1);
    for (int i = 2; i <= N; i++) {
        for (int j = i*2; j <= N; j += i) {
            comp[j] = 1;
        }
    }
    for (int i = 2; i <= N; i++)
        if (!comp[i])
            primes.push_back(i);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; a[x] = 1;
    }
    for (int i = 1; i <= N; i++)
        p[i] = a[i] + p[i-1];
    ll res = 0;
    for (int i = 2; i <= N; i++) {
        ll cnt = 0, ps = 0;
        for (int q : primes) {
            if (i*q > N)
                break;
            if (a[i*q] == 0)
                continue;
            res += cnt * p[i*q] - ps - cnt;
            ps += p[i*q];
            cnt++;
        }
        cout << i << " " << res << "\n";
    }
    cout << (n * (n-1) * (n-2)) / 6 - res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

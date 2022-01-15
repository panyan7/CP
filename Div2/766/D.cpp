#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
int has[1000010];

int gcd(int a, int b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// check long long
void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    memset(has, 0, sizeof(has));
    for (int i = 0; i < n; i++) {
        has[a[i]] = 1;
    }
    int cnt = 0;
    for (int p = 1; p <= 1e6; p++) {
        if (has[p])
            continue;
        int g = -1;
        for (int i = 1; i*p <= 1e6; i++) {
            if (has[i*p]) {
                if (g == -1)
                    g = i;
                else
                    g = gcd(g, i);
            }
        }
        if (g == 1)
            cnt++;
    }
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

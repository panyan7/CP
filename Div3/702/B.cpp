#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    cin >> n;
    array<int,3> c = {0,0,0};
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        c[x % 3]++;
    }
    int cnt = 0;
    for (int i = 0; i < 3; ++i) {
        if (c[i] > n/3) {
            c[(i+1)%3] += c[i] - n/3;
            cnt += c[i] - n/3;
            c[i] = n/3;
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (c[i] > n/3) {
            c[(i+1)%3] += c[i] - n/3;
            cnt += c[i] - n/3;
            c[i] = n/3;
        }
    }
    cout << cnt << "\n";
    //cout << (abs(n/3-c[0]) + abs(n/3-c[1]) + abs(n/3-c[2]))/2 << "\n";
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

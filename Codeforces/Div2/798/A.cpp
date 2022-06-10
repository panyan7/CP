#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    string c;
    int a_cnt = 0, b_cnt = 0;
    int i = 0, j = 0;
    while (true) {
        if (i == n || j == m)
            break;
        if (a_cnt == k) {
            c += b[j];
            j++;
            b_cnt++;
            a_cnt = 0;
        } else if (b_cnt == k) {
            c += a[i];
            i++;
            a_cnt++;
            b_cnt = 0;
        } else {
            if (a[i] < b[j]) {
                c += a[i];
                i++;
                a_cnt++;
                b_cnt = 0;
            } else {
                c += b[j];
                j++;
                b_cnt++;
                a_cnt = 0;
            }
        }
    }
    cout << c << "\n";
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

// Undecidable
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ld PI = acos(0) * 2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll r, s, h;
    cin >> r >> s >> h;
    ld y = PI * (ld)(r * 2) / (ld)(s * h);
    ld d = round(y);
    y -= d;
    int b = (y >= 0 ? 1 : -1);
    ld best = 7e9;
    int res[3];
    for (int n1 = 2; n1 <= 1000; n1++) {
        for (int n2 = 2*n1; n2 <= 1000; n2 += n1) {
            for (int n3 = 2*n2; n3 <= 1000; n3 += n2) {
                ld e = y*n3 - (ld)b*((n3/n1) - (n3/n2) + 1);
                e = abs(e);
                e /= (ld)n3;
                if (e < best) {
                    res[0] = n1;
                    res[1] = n2;
                    res[2] = n3;
                    best = e;
                }
            }
        }
    }
    cout << res[0] << " " << res[1] << " " << res[2] << "\n";
}


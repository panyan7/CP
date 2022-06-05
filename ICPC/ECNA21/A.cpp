#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll val[] = {
    6,
    8,
    9,
    11,
    16,
    21,
    24,
    26,
    28,
    31,
    33,
    36,
    41,
    42,
    51,
    61,
    63,
    111,
    121,
    131,
    132,
    144,
    211,
    221,
    222,
    231,
    311,
    1111,
    1121,
    1211,
    1221,
    1232,
    2111,
    2121,
    8444,
    11111,
    11211,
    11221,
    12321,
    21111

};

#define SZ 100000 + 10
ll dp[100000 + 10];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    std::set<int> possib;

    ll n;
    cin >> n;

    for (int i = 0; i < sizeof(dp) / sizeof(ll); i++) dp[i] = 1000000000;

    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i], dp[i - 1] + 1);


        ll base = 1;
        ll tmp = i;
        ll tmp2 = 0;
        for (int j = 0; j < 6; j++) {
            ll z = tmp % 10;
            tmp2 += base * z;
            tmp /= 10;

            if (z != 0) {
                dp[i] =  min(dp[i], dp[tmp2] + dp[tmp]);
            }

            base *= 10;

            assert(tmp == i / base);
            assert(tmp2 == i % base);
        }

        for (int j: val) {
            if (i - j > 0) {
                dp[i] = min(dp[i], dp[i - j] + dp[j]);
            }
        }

        for (int j = 2; j <= i; j++) {
            if (j * i > SZ - 1) break;
            dp[j * i] = min(dp[j * i], dp[i] + dp[j]);
        }
    }

    cout << dp[n] << endl;

    return 0;
}


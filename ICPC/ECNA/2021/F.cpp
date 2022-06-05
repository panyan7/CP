#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define SZ 100 + 10
#define EPS 0.00000001

bool valid[SZ];
ld x[SZ], y[SZ], rate[SZ], r[SZ];

ld dist(int a, int b) {
    return sqrt(pow(x[a] - x[b], 2.0) + pow(y[a] - y[b], 2));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        valid[i] = true;
        cin >> x[i] >> y[i] >> r[i] >> rate[i];
    }

    while (true) {
        int min_idx = -1;
        int min_j = -1;
        ld min_time = 1e40;
        for (int i = 0; i < n; i++) {
            if (!valid[i]) continue;
            for (int j = 0; j < n; j++) {
                if (!valid[j]) continue;

                if (i == j) continue;

                ld nxt_time = (dist(i, j) - r[i] - r[j]) / (rate[i] + rate[j]);
                if (nxt_time < min_time) {
                    min_idx = i;
                    min_j = j;
                    min_time = nxt_time;
                }
            }
        }

        assert(min_idx != -1);

        for (int i = 0; i < n; i++) {
            if (valid[i]) {
                r[i] += min_time * rate[i];
            }
        }

        bool found = true;
        while (found) {
            found = false;

            int cnt = 1;
            ld x2 = x[min_idx];
            ld y2 = y[min_idx];
            ld area = pow(r[min_idx], 2);

            for (int i = 0; i < n; i++) {
                if (!valid[i]) continue;
                if (i == min_idx) continue;

                if (dist(i, min_idx) - r[i] - r[min_idx] < EPS) {
                    found = true;
                    valid[i] = false;
                    cnt++;
                    x2 += x[i];
                    y2 += y[i];
                    area += pow(r[i], 2);
                    rate[min_idx] = max(rate[min_idx], rate[i]);
                }
            }

            x[min_idx] = x2 / cnt;
            y[min_idx] = y2 / cnt;
            r[min_idx] = sqrt(area);
        }

        assert(!valid[min_j]);

        int valid_cnt = 0;
        for (int i = 0; i < n; i++) {
            if (valid[i]) valid_cnt++;
        }
        if (valid_cnt == 1) break;
        assert(valid_cnt > 1);
    }

    for (int i = 0; i < n; i++) {
        if (valid[i]) {
            cout << fixed << setprecision(15) << x[i] << " " << y[i] << endl;
            cout << r[i] << endl;
        }
    }


    return 0;
}


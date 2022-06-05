#include "bits/stdc++.h"
using namespace std;
 
typedef int64_t ll;
ll a[10], b[10];
ll u[10], r[10], t[10];
 
int main() {
    int n = 10;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
 
    for (int i = 0; i < n; i++) {
        cin >> u[i] >> r[i] >> t[i];
    }
 
    ll tm = 0;
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 10; i++) {
            ll k = max((ll)0LL, (tm - t[i]) / (u[i] + r[i]));
            t[i] += (u[i] + r[i]) * k;
            if (t[i] > tm) {
                // the person hasn't start, just use it now
            } else if (t[i] + u[i] > tm) {
                // the person is using it, wait
                tm = t[i] + u[i];
                t[i] += u[i] + r[i];
            } else {
                assert(t[i] + u[i] <= tm);
                // the person just finished using it and is recovering
                t[i] += u[i] + r[i];
            }
 
            tm += a[i];
 
            t[i] = max(t[i], tm);
 
            tm += b[i];
 
            // update the tm that person i finish using
        }
    }
    tm -= b[9];
    cout << tm << "\n";
 
    return 0;
}

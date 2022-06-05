#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int p1, u1, p2, u2;
int cp[105], cu[105], wp[105], wu[105];
bool vp[105], vu[105], wantPinned[105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> p1 >> u1;
    for (int i = 0; i < p1; i++) cin >> cp[i];
    for (int i = 0; i < u1; i++) cin >> cu[i];

    cin >> p2 >> u2;
    for (int i = 0; i < p2; i++) cin >> wp[i];
    for (int i = 0; i < u2; i++) cin >> wu[i];

    for (int i = 0; i < p2; i++) wantPinned[wp[i]] = true;
    for (int i = 0; i < u2; i++) wantPinned[wu[i]] = false;

    int ind = 0;
    for (int i = 0; i < p1; i++) {
        if (ind < p2 && cp[i] == wp[ind]) {
            vp[i] = true;
            ind++;
        }
    }

    ind = 0;
    for (int i = 0; i < u1; i++) {
        if (ind < u2 && cu[i] == wu[ind]) {
            vu[i] = true;
            ind++;
        }
    }

    int res = 0;
    for (int i = 0; i < p1; i++) {
        if (!vp[i] && wantPinned[cp[i]]) res += 2;
        else if (!vp[i]) res += 1;
    }

    for (int i = 0; i < u1; i++) {
        if (!vu[i] && !wantPinned[cu[i]]) res += 2;
        else if (!vu[i]) res += 1;
    }

    cout << res << endl;

    return 0;
}


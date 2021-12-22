#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
const int Q = 13;
vector<int> query[Q];
int masks[2005];
ll query_res[Q];

// check long long
void solve() {
    k = 0;
    cin >> n;
    for (int i1 = 0; i1 < Q; i1++) {
        for (int i2 = i1+1; i2 < Q; i2++) {
            for (int i3 = i2+1; i3 < Q; i3++) {
                for (int i4 = i3+1; i4 < Q; i4++) {
                    for (int i5 = i4+1; i5 < Q; i5++) {
                        for (int i6 = i5+1; i6 < Q; i6++) {
                            int mask = (1 << i1) | (1 << i2) | (1 << i3) | (1 << i4) | (1 << i5) | (1 << i6);
                            masks[k] = mask;
                            if (k < n) {
                                query[i1].push_back(k);
                                query[i2].push_back(k);
                                query[i3].push_back(k);
                                query[i4].push_back(k);
                                query[i5].push_back(k);
                                query[i6].push_back(k);
                            }
                            k++;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < Q; i++) {
        if ((int)query[i].size() == 0)
            continue;
        cout << "? " << query[i].size() << " ";
        cout.flush();
        for (int j = 0; j < (int)query[i].size(); j++) {
            cout << query[i][j]+1 << " \n"[j+1==(int)query[i].size()];
            cout.flush();
        }
        cin >> query_res[i];
    }
    cout << "! ";
    cout.flush();
    for (int i = 0; i < n; i++) {
        ll res = 0;
        for (int j = 0; j < Q; j++) {
            if (!(masks[i] & (1 << j))) {
                res |= query_res[j];
            }
        }
        cout << res << " \n"[i+1==n];
        cout.flush();
    }
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

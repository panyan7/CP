#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n+1, 0);
    vector<int> s(n);
    for (auto& x : a)
        cin >> x;
    int mex = 0;
    for (int i = n-1; i >= 0; i--) {
        cnt[a[i]]++;
        if (a[i] == mex) {
            while (mex <= n && cnt[mex] > 0)
                mex++;
        }
        s[i] = mex;
    }
    vector<int> b;
    int i = 0; mex = 0;
    cnt.assign(n+1, 0);
    while (i < n) {
        for (int j = 0; j < mex; j++)
            cnt[j] = 0;
        b.push_back(s[i]);
        if (s[i] == 0) {
            i++;
            continue;
        }
        mex = 0;
        int j = i;
        while (j < n && mex < s[i]) {
            cnt[a[j]]++;
            if (a[j] == mex) {
                while (mex <= n && cnt[mex] > 0)
                    mex++;
            }
            j++;
        }
        i = j;
    }
    cout << b.size() << "\n";
    for (int i = 0; i < (int)b.size(); i++)
        cout << b[i] << " ";
    cout << "\n";
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

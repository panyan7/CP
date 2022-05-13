#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    string s;
    cin >> s;
    vector<int> l, r;
    n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            l.push_back(i+1);
    }
    for (int i = n-1; i >= 0; i--)
        if (s[i] == '1')
            r.push_back(n-i);
    int num_one = l.size();
    if (num_one == 0) {
        cout << "0\n";
        return;
    }
    int num_zero = s.size() - num_one;
    int lo = 0, hi = num_one;
    auto check = [&](int mid) {
        //cout << mid << "\n";
        for (int i = 0; i <= mid; i++) {
            // remove mid 1's
            int removed = l[i] + r[mid-i] - 2;
            int remain_zero = num_zero - (removed - mid);
            //cout << l[i] << " " << r[mid-i] << " ";
            //cout << removed << " " << remain_zero << "\n";
            if (remain_zero <= mid)
                return true;
        }
        return false;
    };
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    if (l[0] + r[0] - 2 == num_zero)
        cout << "0\n";
    else
        cout << hi << "\n";
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

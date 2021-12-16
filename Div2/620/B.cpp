#include <bits/stdc++.h>
using namespace std;

int n, m, r, p;
string lft, mid;
vector<string> s, sr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    s.assign(n, string (m, 0));
    sr.assign(n, string (m, 0));
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        sr[i] = s[i];
        reverse(sr[i].begin(), sr[i].end());
    }
    // lft.assign("");
    for (int i = 0; i < n; ++i) {
        ++p;
        if (s[i].compare(sr[i]) != 0) --p;
        else mid = s[i];
        for (int j = i+1; j < n; ++j) {
            if (s[i].compare(sr[j]) == 0) {
                ++r;
                lft += s[i];
            }
        }
    }
    cout << (2*r+(int)(p>0))*m << "\n";
    cout << lft + mid;
    reverse(lft.begin(), lft.end());
    cout << lft << "\n";
    return 0;
}

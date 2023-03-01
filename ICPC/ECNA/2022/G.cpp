// Undecidable
#include <bits/stdc++.h>
using namespace std;

string int_to_string(int x) {
    string res;
    while (x > 0) {
        res.push_back((x % 10) + '0');
        x /= 10;
    }
    reverse(res.begin(), res.end());
    if (res.size() == 0)
        return "0";
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string n, m;
    cin >> n >> m;
    int res = 1;
    if (n == m) {
        cout << 1 << "\n";
        return 0;
    }
    set<string> st;
    st.insert(n);
    while (true) {
        string nn;
        vector<int> cnt(10, 0);
        for (int i = 0; i < n.size(); i++) {
            cnt[n[i]-'0']++;
        }
        for (int i = 0; i < 10; i++) {
            if (cnt[i] == 0)
                continue;
            nn += int_to_string(cnt[i]);
            nn.push_back(i + '0');
        }
        n = nn;
        // cout << n << "\n";
        if (st.count(n))
            break;
        st.insert(n);
        res++;
        if (res > 100) {
            cout << "I'm bored\n";
            return 0;
        }
        if (n == m) {
            cout << res << "\n";
            return 0;
        }
    }
    cout << "Does not appear\n";
}


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

template <typename T>
class RMQ {
    vector<vector<T>> spt;
    int n, lim;
private:
    void _build (const vector<T>& a) {
        spt.assign(lim+1, vector<T>(n, 0));
        for (int i = 0; i < n; ++i)
            spt[0][i] = a[i];
        for (int k = 1; k <= lim; ++k)
            for (int i = 0; i <= n-(1<<k); ++i)
                spt[k][i] = max(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
    }
public:
    RMQ(const vector<T>& a) :
        n(a.size()), lim(floor(log2(n)+1)) { _build(a); }
    T query(int i, int j) const {
        int k = floor(log2(j-i+1));
        T res = max(spt[k][i], spt[k][j-(1<<k)+1]);
        return res;
    }
};

int t = 1, n, m, k, q;

void solve() {
    cin >> n;
    vector<int> loc(n);
    vector<int> a(n);
    vector<int> d(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; --a[i];
        loc[a[i]] = i;
    }
    RMQ<int> Q(a);
    function<void(int,int,int)> dvq = [&](int l, int r, int depth) {
        if (l > r)
            return;
        if (l == r) {
            d[l] = depth;
            return;
        }
        int mid = loc[Q.query(l, r)];
        d[mid] = depth;
        dvq(l, mid-1, depth+1);
        dvq(mid+1, r, depth+1);
    };
    dvq(0, n-1, 0);
    for (int i = 0; i < n; ++i) {
        cout << d[i] << " \n"[i+1==n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

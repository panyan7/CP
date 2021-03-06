#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

struct RandomHash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};
struct SplitMixHash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
struct StringHash {
    static uint64_t hash_str(string const& s) {
        const uint64_t p = 31;
        const uint64_t m = 1e9 + 7;
        uint64_t h = 0;
        uint64_t p_pow = 1;
        for (char c : s) {
            h = (h + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return h;
    }
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(const string& s) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(hash_str(s) + FIXED_RANDOM);
    }
};

typedef unordered_set<int, SplitMixHash> safe_set;
typedef unordered_map<string, safe_set, StringHash> safe_map;

int tt = 1, n, m, k;
safe_map mp;

void solve() {
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int l = 1; l <= 9; l++) {
            for (int j = 0; j + l <= 9; j++) {
                mp[s[i].substr(j, l)].insert(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int l = 1; l <= 9; l++) {
            bool ok = false;
            for (int j = 0; j + l <= 9; j++) {
                if (mp[s[i].substr(j, l)].size() == 1) {
                    ok = true;
                    cout << s[i].substr(j, l) << "\n";
                    break;
                }
            }
            if (ok)
                break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>
#define ld long double
#define pt  std::array<long double,2>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
 
bool cw(pt a, pt b, pt c) {
    return a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1]) < 0;
}
bool ccw(pt a, pt b, pt c) {
    return a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1]) > 0;
}
vector<pair<pt,int> > convex_hull(vector<pair<pt,int> >& a) {
    if (a.size() == 1)
        return {};
    sort(a.begin(), a.end());
    vector<pair<pt,int> > b;
    b.push_back(a[0]);
    for (int i = 0; i+1 < (int)a.size(); i++) {
        ld xd = a[i+1].first[0] - a[i].first[0], yd = a[i+1].first[1] - a[i].first[1];
        ld d = sqrt(xd * xd + yd * yd);
        if (d > 1e-10)
            b.push_back(a[i+1]);
    }
    a = b;
    //a.erase(unique(a.begin(), a.end()), a.end());
    pair<pt,int> p1 = a[0], p2 = a.back();
    vector<pair<pt,int> > u, d;
    u.push_back(p1);
    d.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1.first, a[i].first, p2.first)) {
            while (u.size() >= 2 && !cw(u[u.size()-2].first, u[u.size()-1].first, a[i].first))
                u.pop_back();
            u.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1.first, a[i].first, p2.first)) {
            while (d.size() >= 2 && !ccw(d[d.size()-2].first, d[d.size()-1].first, a[i].first))
                d.pop_back();
            d.push_back(a[i]);
        }
    }
    vector<pair<pt, int> > res;
    for (int i = 0; i < (int)u.size(); i++)
        res.push_back(u[i]);
    for (int i = d.size() - 2; i > 0; i--)
        res.push_back(d[i]);
    return res;
}
 
int tt = 1, n, m;
 
void solve() {
    cin >> n;
    vector<std::array<ld,3> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][2] += 10.0;
    }
    vector<pair<pt, int> > v;
    vector<bool> ok(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            ld xd = a[j][0] - a[i][0], yd = a[j][1] - a[i][1];
            if (xd == 0.0 && yd == 0.0)
                continue;
            ld gamma = -atan2(yd, xd);
            ld d = sqrt(xd * xd + yd * yd);
            ld alpha = atan2(yd, xd);
            if (d <= abs(a[j][2] - a[i][2])) {
                if (a[j][2] > a[i][2])
                    ok[i] = false;
                else
                    ok[j] = false;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (!ok[i] || !ok[j])
                continue;
            //cout << i << " " << j << ":\n";
            ld xd = a[j][0] - a[i][0], yd = a[j][1] - a[i][1];
            if (xd == 0.0 && yd == 0.0)
                continue;
            ld gamma = -atan2(yd, xd);
            ld d = sqrt(xd * xd + yd * yd);
            ld alpha = atan2(yd, xd);
            v.push_back({{a[i][0] + a[i][2] * sin(alpha), a[i][1] + a[i][2] * cos(alpha)}, i});
            v.push_back({{a[i][0] - a[i][2] * sin(alpha), a[i][1] - a[i][2] * cos(alpha)}, i});
            v.push_back({{a[j][0] + a[j][2] * sin(alpha), a[j][1] + a[j][2] * cos(alpha)}, j});
            v.push_back({{a[j][0] - a[j][2] * sin(alpha), a[j][1] - a[j][2] * cos(alpha)}, j});
            //cout << i << " " << j << "\n";
            ld beta = asin(abs(a[j][2] - a[i][2]) / d);
            v.push_back({{a[i][0] + a[i][2] * sin(gamma - beta), a[i][1] + a[i][2] * cos(gamma - beta)}, i});
            v.push_back({{a[i][0] + a[i][2] * sin(gamma + beta), a[i][1] + a[i][2] * cos(gamma + beta)}, i});
            v.push_back({{a[j][0] + a[j][2] * sin(gamma - beta), a[j][1] + a[j][2] * cos(gamma - beta)}, j});
            v.push_back({{a[j][0] + a[j][2] * sin(gamma + beta), a[j][1] + a[j][2] * cos(gamma + beta)}, j});
            v.push_back({{a[i][0] - a[i][2] * sin(gamma - beta), a[i][1] - a[i][2] * cos(gamma - beta)}, i});
            v.push_back({{a[i][0] - a[i][2] * sin(gamma + beta), a[i][1] - a[i][2] * cos(gamma + beta)}, i});
            v.push_back({{a[j][0] - a[j][2] * sin(gamma - beta), a[j][1] - a[j][2] * cos(gamma - beta)}, j});
            v.push_back({{a[j][0] - a[j][2] * sin(gamma + beta), a[j][1] - a[j][2] * cos(gamma + beta)}, j});
        }
    }
 
    if (v.size() == 0) {
        ld r = 0;
        for (int i = 0; i < n; i++)
            r = max(r, a[i][2]);
        cout << fixed << setprecision(10) << 2 * M_PI * r << "\n";
        return;
    }
 
    vector<pair<pt, int> > ch = convex_hull(v);
    assert(ch.size() > 0);
    ch.push_back(ch[0]);

    ld res = 0.0;
    for (int i = 0; i+1 < (int)ch.size(); i++) {
        ld x1 = ch[i].first[0], y1 = ch[i].first[1];
        ld x2 = ch[i+1].first[0], y2 = ch[i+1].first[1];
        ld x = x2 - x1, y = y2 - y1;
        ld d = sqrt((x * x) + (y * y));
        ld v = 0.0;
        if (ch[i].second == ch[i+1].second) {
            int j = ch[i].second;
            ld xr = a[j][0], yr = a[j][1], r = a[j][2];
            ld theta = asin(d / (2 * r));
            if ((x1 - xr) * (y2 - yr) - (y1 - yr) * (x2 - xr) > 0) {
                // v = 2 * theta * r;
                v = (2 * M_PI - 2 * theta) * r;
            } else {
                v = 2 * theta * r;
            }
        } else {
            v = d;
        }
        res += v;
    }
    cout << fixed << setprecision(10) << res << "\n";
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

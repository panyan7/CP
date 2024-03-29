#include <bits/stdc++.h>
using namespace std;
const double PI = 2*acos(0);

const double EPS = 1e-9;
template <typename T>
struct Point {
    T x, y;
    Point() : x(0.0), y(0.0) {}
    Point(T x, T y) : x(x), y(y) {}
    Point(vector<T>& a) : x(a[0]), y(a[1]) {}
    friend ostream& operator<<(ostream& os, const Point& a) {
        return os << "(" << a.x << "," << a.y << ")";
    }
    friend istream& operator>>(istream& is, Point& a) {
        return is >> a.x >> a.y;
    }
    friend bool operator==(const Point& a, const Point& b) {
        return a.x == b.x && a.y == b.y;
    }
    friend bool operator!=(const Point& a, const Point& b) { return !(a == b); }
    friend bool operator<(const Point& a, const Point& b) {
        return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
    }
    Point& operator+=(const Point& a) {
        x += a.x;
        y += a.y;
        return *this;
    }
    Point& operator-=(const Point& a) {
        x -= a.x;
        y -= a.y;
        return *this;
    }
    Point& operator*=(const double c) {
        x *= c;
        y *= c;
        return *this;
    }
    Point& operator/=(const double c) {
        x /= c;
        y /= c;
        return *this;
    }
    friend Point operator+(const Point& a, const Point& b) { return Point(a) += b; }
    friend Point operator-(const Point& a, const Point& b) { return Point(a) -= b; }
    friend Point operator*(const Point& a, const double c) { return Point(a) *= c; }
    friend Point operator*(const double c, const Point& a) { return Point(a) *= c; }
    friend Point operator/(const Point& a, const double c) { return Point(a) /= c; }
    friend T dot(Point a, Point b)       { return a.x * b.x + a.y * b.y; }
    friend T cross(Point a, Point b)     { return a.x * b.y - a.y * b.x; }
    friend T len2(Point a)               { return a.x * a.x + a.y * a.y; }
    friend double len(Point a)           { return sqrt((double)len2(a)); }
    friend T dist2(Point a, Point b)     { return len2(a - b); }
    friend double dist(Point a, Point b) { return len(a - b); }
    friend Point intersect(Point a1, Point d1, Point a2, Point d2) {
        // intersection between a1 + td1 and a2 + td2
        assert(d1 != d2);
        return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
    }
    friend double polygon_area(const vector<Point>& fig) {
        double res = 0;
        for (int i = 0; i < (int)fig.size(); i++) {
            Point p = i ? fig[i - 1] : fig.back();
            Point q = fig[i];
            res += (p.x - q.x) * (p.y + q.y);
        }
        return fabs(res) / 2.0;
    }
    friend Point proj(Point a, Point b) {
        return b * dot(a, b) / dot(b, b);
    }
    friend double dist_to_line(Point a, Point b, Point c) {
        // distance to line bc
        assert(b != c);
        Point ba = a - b;
        Point bc = c - b;
        Point proj_ba_bc = proj(ba, bc);
        Point rem = ba - proj_ba_bc;
        return len(rem);
    }
    friend double vdist_to_line(Point a, Point b, Point c) {
        // vertical distance to line bc
        assert(b != c);
        double res = b.y - (b.x-a.x)/(c.x-b.x)*(c.y-b.y) - a.y;
        return res;
    }
    friend int orientation(Point a, Point b, Point c) {
        T v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
        if (v < 0) return -1; // clockwise
        if (v > 0) return +1; // counter-clockwise
        return 0;
    }
    friend bool cw(Point a, Point b, Point c, bool include_collinear=false) {
        int o = orientation(a, b, c);
        return o < 0 || (include_collinear && o == 0);
    }
    friend bool ccw(Point a, Point b, Point c, bool include_collinear=false) {
        int o = orientation(a, b, c);
        return o > 0 || (include_collinear && o == 0);
    }
    friend bool collinear(Point a, Point b, Point c) {
        return orientation(a, b, c) == 0;
    }
    friend vector<Point> convex_hull(vector<Point>& a, bool include_collinear=false,
                                     bool upper_set=false) {
        // Convex hull, clockwise
        if (a.size() == 1)
            return a;
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        Point p1 = a[0], p2 = a.back();
        vector<Point> u, d;
        u.push_back(p1);
        d.push_back(p1);
        for (int i = 1; i < (int)a.size(); i++) {
            if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
                while (u.size() >= 2
                       && !cw(u[u.size()-2], u[u.size()-1], a[i], include_collinear))
                    u.pop_back();
                u.push_back(a[i]);
            }
            if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
                while (d.size() >= 2
                       && !ccw(d[d.size()-2], d[d.size()-1], a[i], include_collinear))
                    d.pop_back();
                d.push_back(a[i]);
            }
        }
        if (include_collinear && a.size() == u.size()) {
            vector<Point> res = a;
            reverse(res.begin(), res.end());
            return res;
        }
        vector<Point> res;
        for (int i = 0; i < (int)u.size(); i++)
            res.push_back(u[i]);
        if (upper_set)
            return res;
        for (int i = (int)d.size() - 2; i > 0; i--)
            res.push_back(d[i]);
        return res;
    }
    friend bool compare_angles(Point u, Point v1, Point v2) {
        // Compare the angles between (u, v1) and (u, v2)
        T f1 = dot(u, v1) * abs(dot(u, v1)) * len2(v2);
        T f2 = dot(u, v2) * abs(dot(u, v2)) * len2(v1);
        return f1 < f2;
    };
};
struct Line {
    double a, b, c;
    Line() : a(0.0), b(0.0), c(0.0) {}
    Line(double a, double b, double c) : a(a), b(b), c(c) {}
    friend ostream& operator<<(ostream& os, const Line& l) {
        return os << l.a << " " << l.b << " " << l.c;
    }
    friend Line offset(Line l, Point<double> a, bool invert=false) {
        // invert = false then (0,0) -> a, true then a -> (0,0)
        if (invert)
            l.c += l.a * a.x + l.b * a.y;
        else
            l.c -= l.a * a.x + l.b * a.y;
        return l;
    }
};
struct Circle {
    Point<double> c;
    double r;
    Circle() : r(0.0) {}
    Circle(double r) : r(r) {}
    Circle(Point<double> c, double r) : c(c), r(r) {}
    friend ostream& operator<<(ostream& os, const Circle& a) {
        return os << a.c << " " << a.r;
    }
    friend istream& operator>>(istream& is, Circle& a) {
        return is >> a.c >> a.r;
    }
    void line_circle_intersection(Circle a, Line l, vector<Point<double>>& ans) {
        l = offset(l, a.c, true);
    }
    void tangent_circle(Circle a, Circle b, vector<Line>& ans) {
        auto tangent_line = [&](Point<double> c, double r1, double r2) {
            double r = r2 - r1;
            double z = c.x * c.x + c.y * c.y;
            double d = z - r * r;
            if (d < -EPS) return;
            d = sqrt(abs(d));
            Line l;
            l.a = (c.x * r + c.y * d) / z;
            l.b = (c.y * r - c.x * d) / z;
            l.c = r1; 
            l = offset(l, a.c);
            ans.push_back(l);
        };
        for (int i = -1; i <= 1; i += 2)
            for (int j = -1; j <= 1; j += 2)
                tangent_line(b.c - a.c, a.r * i, b.r * j);
    }
};

using pt = Point<double>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cc = 0;
    int tt; cin >> tt;
    while (tt--) {
        cc++;
        vector<pt> a(4);
        for (int i = 0; i < 4; i++)
            cin >> a[i];
        cout << "Case " << cc << ": ";
        vector<pt> b = convex_hull(a);
        // for (auto& x : b) cout << x << " ";
        if (b.size() < 4) {
            cout << "no solution\n";
            continue;
        }
        double c = b[1].y - b[3].y + b[0].x - b[2].x;
        double d = b[1].x - b[3].x + b[2].y - b[0].y;
        double theta_ub = atan2(b[1].y-b[0].y, b[1].x-b[0].x);
        double theta_lb = atan2(b[3].y-b[0].y, b[3].x-b[0].x);
        if (c == 0 && d == 0) {
            // infinitely many solutions
            cout << fixed << setprecision(2) << dist(b[2], b[0]) + 10.0 << "\n";
            continue;
        }
        if (theta_ub < 0)
            theta_ub += PI;
        if (theta_lb > 0)
            theta_lb -= PI;
        double theta = atan2(c, d);
        if (theta >= theta_ub || theta <= theta_lb) {
            theta = theta + PI/2;
        }
        if (theta >= theta_ub || theta <= theta_lb) {
            theta = theta + PI/2;
        }
        if (theta >= theta_ub || theta <= theta_lb) {
            theta = theta - 2*PI;
        }
        if (theta >= theta_ub || theta <= theta_lb) {
            theta = theta + PI/2;
        }
        if (theta >= theta_ub || theta <= theta_lb) {
            cout << "no solution\n";
            continue;
        }
        // cout << theta_ub << " " << theta_lb << " " << theta << " ";
        double len1 = (b[2].x - b[0].x) * cos(theta) + (b[2].y - b[0].y) * sin(theta);
        double len2 = (b[3].x - b[1].x) * sin(theta) + (b[1].y - b[3].y) * cos(theta);
        vector<double> proj_x(4), proj_y(4);
        for (int i = 0; i < 4; i++) {
            proj_x[i] = b[i].x * cos(theta) + b[i].y * sin(theta);
            proj_y[i] = -b[i].y * cos(theta) + b[i].x * sin(theta);
        }
        // for (int i = 0; i < 4; i++)
            // cout << proj_x[i] << " " << proj_y[i] << " ";
        if (proj_x[0] >= proj_x[2])
            for (int i = 0; i < 4; i++)
                proj_x[i] = -proj_x[i];
        if (proj_y[1] >= proj_y[3])
            for (int i = 0; i < 4; i++)
                proj_y[i] = -proj_y[i];
        bool not_ok = false;
        for (int i = 0; i < 4; i++) {
            if (proj_x[i] <= proj_x[0]+EPS && i != 0) {
                cout << "no solution\n";
                not_ok = true;
                break;
            } else if (proj_x[i] >= proj_x[2]-EPS && i != 2) {
                cout << "no solution\n";
                not_ok = true;
                break;
            }
        }
        if (not_ok)
            continue;
        for (int i = 0; i < 4; i++) {
            if (proj_y[i] >= proj_y[3]-EPS && i != 3) {
                cout << "no solution\n";
                not_ok = true;
                break;
            } else if (proj_y[i] <= proj_y[1]+EPS && i != 1) {
                cout << "no solution\n";
                not_ok = true;
                break;
            }
        }
        if (not_ok)
            continue;
        cout << fixed << setprecision(2) << abs(len1) + 10.0 << "\n";
    }
}

// divide_and_conquer sorting
// https://open.kattis.com/problems/closestpair1
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <utility>
#include <queue>
#include <iomanip>
#include <deque>
#include <set>

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9
#define EPS 1e-9

using ull = unsigned long long;
using ll = long long;
using namespace std;

struct Point {
    Point() : x(0), y(0) {}
    Point(double px, double py) : x(px), y(py) {}

    double x, y;
};
struct Sol {
    Sol(double s, Point pa, Point pb) : sol(s), a(pa), b(pb) {}

    double sol;
    Point a, b;
};

int n;
Point arr[100010];

bool cmpX(const Point& p1, const Point& p2) {
    if (p1.x == p2.x)   return p1.y < p2.y;
    return p1.x < p2.x;
}
bool cmpY(const Point& p1, const Point& p2) {
    if (p1.y == p2.y)   return p1.x < p2.x;
    return p1.y < p2.y;
}
double dist(const Point& p1, const Point& p2) {
    double xs = (p1.x - p2.x);
    double ys = (p1.y - p2.y);
    return sqrt(xs * xs + ys * ys);
}

Sol calc(int bot, int top) {
    if (top - bot + 1 == 2) {
        return Sol(dist(arr[bot], arr[top]), arr[bot], arr[top]);
    }
    if (top - bot + 1 == 3) {
        double a12 = dist(arr[bot], arr[bot + 1]);
        double a13 = dist(arr[bot], arr[bot + 2]);
        double a23 = dist(arr[bot + 1], arr[bot + 2]);
        if (a12 <= a13 && a12 <= a23)   return Sol(a12, arr[bot], arr[bot + 1]);
        if (a13 <= a12 && a13 <= a23)   return Sol(a13, arr[bot], arr[bot + 2]);
        if (a23 <= a12 && a23 <= a13)   return Sol(a23, arr[bot + 1], arr[bot + 2]);
    }

    int mid = (bot + top) / 2;
    Sol soll = calc(bot, mid), solr = calc(mid + 1, top);

    double d = min(soll.sol, solr.sol);
    vector<Point> ps;
    for (int i = bot; i <= top; i++) {
        if (abs(arr[mid].x - arr[i].x) <= d) {
            ps.push_back(arr[i]);
        }
    }
    sort(ps.begin(), ps.end(), cmpY);

    Sol ans(-1, Point(0, 0), Point(0, 0));
    For (i, ps.size()) {
        for (int j = i + 1; j <= i + 3 && j < ps.size(); j++) {
            double dis = dist(ps[i], ps[j]);
            if (dis < soll.sol && dis < solr.sol) {
                if (ans.sol == -1 || dis < ans.sol) {
                    ans = Sol(dis, ps[i], ps[j]);
                }
            }
        }
    }

    if (ans.sol == -1) {
        if (soll.sol < solr.sol) {
            return soll;
        } else {
            return solr;
        }
    } else {
        return ans;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> n && n != 0) {
        For (i, n) {
            cin >> arr[i].x >> arr[i].y;
        }

        sort(arr, arr + n, cmpX);
        Sol sol = calc(0, n - 1);

        cout << fixed << sol.a.x << ' ' << sol.a.y << ' ' << sol.b.x << ' ' << sol.b.y << '\n';
    }

    return 0;
}
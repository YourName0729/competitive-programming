// BFS
// https://open.kattis.com/problems/enemyterritory
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define forcase int __t;cin >> __t;while (__t--)

#define W 1010

using namespace std;

// class Point {
// public:
//     Point() : x(0), y(0), l(0) {}
//     Point(int a, int b) : x(a), y(b), l(0) {}
//     Point(int a, int b, int ll) : x(a), y(b), l(ll) {}

//     friend Point operator+(const Point& p1, const Point& p2) {
//         return Point(p1.x + p2.x, p1.y + p2.y);
//     }
//     friend Point operator-(const Point& p1, const Point& p2) {
//         return Point(p1.x - p2.x, p1.y - p2.y);
//     }
//     friend istream& operator>>(istream& in, Point& p) {
//         in >> p.x >> p.y;
//         return in;
//     }
//     friend ostream& operator<<(ostream& out, const Point& p) {
//         out << '(' << p.x << ',' << p.y << ')';
//         return out;
//     }
//     friend bool operator==(const Point& p1, const Point& p2) {
//         return p1.x == p2.x && p1.y == p2.y;
//     }

//     bool in(int X, int Y) const {
//         return 0 <= x && x < X && 0 <= y && y < Y;
//     }

//     int x, y, l;
// };

struct Point {
    int x, y, l;
};
Point point(int a, int b, int c) {
    Point re;
    re.x = a; re.y = b; re.l = c;
    return re;
}
bool legal(const Point p, int X, int Y) {
    return 0 <= p.x && p.x < X && 0 <= p.y && p.y < Y;
}

int n, X, Y;
int m[W][W];
queue<Point> que;
Point s, d;

//const Point drct[4] = {Point(1, 0), Point(0, -1), Point(-1, 0), Point(0, 1)};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void build() {
    memset(m, -1, sizeof(m[0][0]) * W * W);

    /*for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            m[i][j] = X + Y;
        }
    }*/

    while (!que.empty()) {
        Point p = que.front();
        que.pop();

        if (m[p.x][p.y] != -1)  continue;
        m[p.x][p.y] = p.l;

        for (int i = 0; i < 4; i++) {
            Point go = point(p.x + dx[i], p.y + dy[i], p.l + 1);
            if (legal(go, X, Y) && m[go.x][go.y] == -1) {
                que.push(go);
            }
        }
    }
}

bool travel[W][W];
int step(int limit) {
    memset(travel, false, sizeof(travel[0][0]) * W * W);
    /*for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            travel[i][j] = false;
        }
    }*/

    while (!que.empty()) que.pop();
    que.push(s);

    while (!que.empty()) {
        Point p = que.front();
        que.pop();

        if (travel[p.x][p.y])   continue;
        travel[p.x][p.y] = true;
        if (p.x == d.x && p.y == d.y) {
            /**cout << limit << " ok\n";
            for (int i = 0; i < X; i++) {
                for (int j = 0; j < Y; j++) {
                    cout << travel[i][j] << ' ';
                }
                cout << '\n';
            }*/
            return p.l;
        } 
        

        for (int i = 0; i < 4; i++) {
            Point go = point(p.x + dx[i], p.y + dy[i], p.l + 1);
            if (legal(go, X, Y) && !travel[go.x][go.y] && m[go.x][go.y] >= limit) {
                //cout << "try go " << go.x << ' ' << go.y << '\n';
                que.push(go);
            }       
        }

        /*for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                cout << travel[i][j];
            }
            cout << '\n';
        }
        cout << '\n';*/
    }

    return -1;
}

int main() {
    fast;

    cin >> n >> X >> Y;
    cin >> s.x >> s.y >> d.x >> d.y;
    s.l = 0;
    for (int i = 0; i < n; i++) {
        Point tmp;
        cin >> tmp.x >> tmp.y;
        tmp.l = 0;
        que.push(tmp);
    }

    build();
    /*for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            cout << m[i][j] << ' ';
        }
        cout << '\n';
    }*/

    int l = 0, r = min(m[s.x][s.y], m[d.x][d.y]);
    while (l != r) {
        int mid = ((l + r) % 2 == 0)? (l + r) / 2 : (l + r) / 2 + 1;
        int ans = step(mid);

        if (ans == -1) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }

    cout << l << ' ' << step(l) << '\n';

    return 0;
}
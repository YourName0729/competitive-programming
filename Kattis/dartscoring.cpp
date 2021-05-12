// https://open.kattis.com/problems/dartscoring
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-12;

int n, m;;
struct Point {double x, y;} P[110], CH[110];
 
double cross(Point o, Point a, Point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
 
bool compare(Point a, Point b)
{
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}
 
void Andrew_monotone_chain() {
    sort(P, P+n, compare);
 
    m = 0;  
 
    for (int i=0; i<n; ++i)
    {
        while (m >= 2 && cross(CH[m-2], CH[m-1], P[i]) <= 0) m--;
        CH[m++] = P[i];
    }
 
    for (int i=n-2, t=m+1; i>=0; --i)
    {
        while (m >= t && cross(CH[m-2], CH[m-1], P[i]) <= 0) m--;
        CH[m++] = P[i];
    }
 
    m--; 
}

double dist(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    while (getline(cin, s)) {
        n = 0;
        stringstream ss;
        ss << s;
        double x, y;
        while (ss >> x >> y) {
            P[n] = Point{x, y};
            n++;
        }
        Andrew_monotone_chain();

        double s = 0;
        if (m != 0)
            For (i, m) {
                s += dist(CH[i], CH[(i + 1) % m]);
            }

        cout << fixed << setprecision(8) << 100 * n / (1 + s) << '\n';
    }

    return 0;
}

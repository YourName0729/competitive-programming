// geometry
// https://open.kattis.com/problems/zipline
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

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9

using ull = unsigned long long;
using ll = long long;
using namespace std;

double w, g, h, r;

double ans() {
    if (g == r || h == r) {
        return sqrt(w * w + (g - h) * (g - h));
    }

    double perc = (g - r) / (h - r);
    double x1 = perc / (perc + 1) * w;
    double x2 = (1 / perc) / ((1 / perc) + 1) * w;

    return sqrt(x1 * x1 + (g - r) * (g - r)) + sqrt(x2 * x2 + (h - r) * (h - r));
}

int main() {

    Forcase {
        cin >> w >> g >> h >> r;
        cout << fixed << sqrt(w * w + (g - h) * (g - h)) << ' ';
    
        cout << fixed << ans() << '\n';
    }

    return 0;
}
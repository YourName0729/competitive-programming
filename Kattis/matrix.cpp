//
// https://open.kattis.com/problems/matrix
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



int main() {

    int a, b, c, d, t = 0;
    while (cin >> a >> b >> c >> d) {
        int det = a * d - b * c;

        cout << "Case " << ++t << ":\n";
        cout << d / det << ' ' << -b / det << '\n';
        cout << -c / det << ' ' << a / det << '\n';
    }

    return 0;
}
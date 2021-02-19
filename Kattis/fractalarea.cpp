// dp
// https://open.kattis.com/problems/fractalarea
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
#include <functional>

#define Forcase int __t;cin>>__t;for(int cases=1;cases<=__t;cases++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9
#define LINF 1e18
#define EPS 1e-9

using ull = unsigned long long;
using ll = long long;
using namespace std;

double pi = 3.141592653589793;

double dp1[210];
double dp2[210];

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    dp1[1] = 1;
    double fac = 0.25;
    for (int i = 2; i < 210; i++) {
        dp1[i] = 4 * fac;
        fac *= 0.75;
    }

    for (int i = 1; i < 210; i++) {
        dp2[i] = dp2[i - 1] + dp1[i];
    }

    Forcase {
        double r;
        int n;
        cin >> r >> n;
        cout << fixed << r * r * pi * dp2[n] << '\n';
    }

    

    return 0;
}
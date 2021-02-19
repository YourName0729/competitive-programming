//
// https://open.kattis.com/problems/falling
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

#define Forcase int __t;cin>>__t;for(int cases=1;cases<=__t;cases++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9
#define LINF 1e18
#define EPS 1e-9

using ull = unsigned long long;
using ll = long long;
using namespace std;

int n;
int con[1010];

bool can() {
    int coda = con[1];
    for (int i = 2; i <= n; i++) {
        if (coda == 0)  return false;
        coda--;
        coda += con[i];
    }
    return coda == 0;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    ll d, a = 0, b = 0;
    cin >> d;
    while (!(b - a == 1 && b * b - a * a > d)) {
        if (b * b - a * a == d) {
            cout << a << ' ' << b << '\n';
            return 0;
        }
        if (b * b - a * a < d) {
            b++;
        } else {
            a++;
        }
    }
    cout << "impossible\n";

    return 0;
}
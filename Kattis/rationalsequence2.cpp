//
// https://open.kattis.com/problems/rationalsequence2
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

int FInv(int p, int q) {
    if (p == 1 && q == 1)   return 1;
    if (p < q) {
        return 2 * FInv(p, q - p);
    }
    if (p > q) {
        return 2 * FInv(p - q, q) + 1;
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n;
    cin >> n;
    For (i, n) {
        int cases, p, q;
        char c;
        cin >> cases >> p >> c >> q;
        cout << cases << ' ' << FInv(p, q) << '\n';
    }
    

    return 0;
}

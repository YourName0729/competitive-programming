//
// https://open.kattis.com/problems/harshadnumbers
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

int dgtSum(int n) {
    int re = 0;
    while (n) {
        re += n % 10;
        n /= 10;
    }
    return re;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n;
    cin >> n;
    while (true) {
        if (n % dgtSum(n) == 0) {
            cout << n << '\n';
            break;
        }
        n++;
    }
    

    return 0;
}

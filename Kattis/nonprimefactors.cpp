// number_theory
// https://open.kattis.com/problems/nonprimefactors
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

const int MAXN = 2000010;
ll fac[MAXN];
ll pfac[MAXN];

int count(int n, int f) {
    int re = 0;
    while (n % f == 0) {
        re++;
        n /= f;
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    For (i, MAXN) {
        fac[i] = 1;
        pfac[i] = 0;
    }

    for (int i = 2; i < MAXN; i++) {
        if (pfac[i] == 0) {
            for (int j = 1; j * i < MAXN; j++) {
                pfac[j * i]++;
                fac[j * i] *= (count(j * i, i) + 1);
            }
        }
    }

    int cases;
    cin >> cases;
    while (cases--) {
        int n;
        cin >> n;
        cout << fac[n] - pfac[n] << '\n';
    }

    return 0;
}

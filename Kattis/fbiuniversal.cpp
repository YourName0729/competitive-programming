//
// https://open.kattis.com/problems/fbiuniversal
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

string ab = "BGIOQSUYZ";
string rep = "8C1005VV2";

string lst = "0123456789ACDEFHJKLMNPRTVWX";

ll idx(char c) {
    For (i, lst.length()) {
        if (c == lst[i])    return i;
    }
}

ll w[8] = {2, 4, 5, 7, 8, 10, 11, 13};
ll check(string& s) {
    ll re = 0;
    For (i, 8) {
        re += w[i] * idx(s[i]);
    }
    return re;
}

ll num(string& s) {
    ll re = 0;
    For (i, 8) {
        re *= 27;
        re += idx(s[i]);
    }
    return re;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t, cases;
    cin >> t;
    while (t--) {
        cin >> cases;

        string s;
        For (i, 9) {
            char c;
            cin >> c;
            s += c;
            For (j, ab.length()) {
                if (s[i] == ab[j]) {
                    s[i] = rep[j];
                }
            }
        }

        ll ch = check(s);
        if (s[8] == lst[ch % 27]) {
            cout << cases << ' ' << num(s) << '\n';
        } else {
            cout << cases << ' ' << "Invalid\n";
        }
    }

    return 0;
}
//
// https://open.kattis.com/problems/periodicstrings
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

string s;

char ch(string& str, int sht, int idx) {
    return str[(-sht + idx + s.length()) % str.length()];
}

bool ok(int k) {
    string seg = s.substr(0, k);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ch(seg, i / k, i % k)) {
            return false;
        }
    }
    return true;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin >> s;

    if (s.length() == 1) {
        cout << 1 << '\n';
    }

    for (int i = 1; i < s.length(); i++) {
        if (s.length() % i == 0 && ok(i)) {
            cout << i << '\n';
            break;
        } else if (i == s.length() - 1) {
            cout << s.length() << '\n';
        }
    }
    

    return 0;
}
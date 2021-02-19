//
// https://open.kattis.com/problems/ummcode
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

bool um(string& s) {
    Fore (c, s) {
        if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
            if (c != 'm' && c != 'u') return false;
        }   
    }
    return true;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    string s, str;
    getline(cin, s);
    stringstream ss;
    ss << s;
    while (ss >> s) {
        if (um(s)) {
            str += s;
        }
    }

    string real;
    Fore (c, str) {
        if (c == 'm' || c == 'u')   real += c;
    }

    for (int i = 0; i < real.size(); i += 7) {
        char c = 0;
        for (int j = i; j < i + 7; j++) {
            c *= 2;
            if (real[j] == 'u') {
                c++;
            }
        }
        cout << c;
    }
    cout << '\n';

    //cout << real << ' ' << str << '\n';

    return 0;
}
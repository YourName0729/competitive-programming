//
// https://open.kattis.com/problems/guess
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

using ull = unsigned long long;
using ll = long long;
using namespace std;

int main() {

    int l = 1, r = 1000;
    cout << (l + r) / 2 << '\n';

    while (true) {
        string s;
        cin >> s;

        if (s == "correct") {
            break;
        } else if (s == "lower") {
            r = (l + r) / 2 - 1;
        } else {
            l = (l + r) / 2 + 1;
        }

        cout << (l + r) / 2 << '\n';
    }

    return 0;
}
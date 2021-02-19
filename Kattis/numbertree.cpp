//
// https://open.kattis.com/problems/numbertree
#include <bits/stdc++.h>

#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

using ll = long long;
using namespace std;


int main() {
    int h;
    string s;

    cin >> h >> s;
    int p = 2;
    while (h) {
        p *= 2;
        h--;
    }

    int idx = 1;
    Fore (c, s) {
        if (c == 'L') {
            idx *= 2;
        } else {
            idx = idx * 2 + 1;
        }
    }

    cout << p - idx << '\n';

    return 0;
}
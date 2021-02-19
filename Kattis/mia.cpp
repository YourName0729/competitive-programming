//
// https://open.kattis.com/problems/mia
#include <vector>
#include <algorithm>
#include <iostream>

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

using ull = unsigned long long;
using ll = long long;
using namespace std;

int main() {

    int s1, s2, r1, r2, a1, a2;
    while (cin >> s1 >> s2 >> r1 >> r2) {
        if (s1 == 0 && s2 == 0 && r1 == 0 && r2 == 0)   break;

        if (s1 > s2)    swap(s1, s2);
        if (r1 > r2)    swap(r1, r2);

        if (s1 == 1 && s2 == 2) {
            a1 = 1000;
        } else if (s1 == s2) {
            a1 = s1 * 100;
        } else {
            a1 = s2 * 10 + s1;
        }

        if (r1 == 1 && r2 == 2) {
            a2 = 1000;
        } else if (r1 == r2) {
            a2 = r1 * 100;
        } else {
            a2 = r2 * 10 + r1;
        }

        if (a1 == a2) {
            cout << "Tie.\n";
        } else if (a1 > a2) {
            cout << "Player 1 wins.\n";
        } else {
            cout << "Player 2 wins.\n";
        }
    }

    return 0;
}
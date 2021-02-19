//
// https://open.kattis.com/problems/yoda
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



int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int a, b;
    vector<int> v1, v2;
    cin >> a >> b;
    while (a != 0 || b != 0) {
        if (a % 10 >= b % 10) {
            v1.push_back(a % 10);
        }
        if (a % 10 <= b % 10) {
            v2.push_back(b % 10);
        }
        a /= 10;
        b /= 10;
    }

    if (v1.size() == 0) {
        cout << "YODA\n";
    } else {
        int d = 0;
        for (int i = v1.size() - 1; i >= 0; i--) {
            d *= 10;
            d += v1[i];
        }
        cout << d << '\n';
    }

    if (v2.size() == 0) {
        cout << "YODA\n";
    } else {
        int d = 0;
        for (int i = v2.size() - 1; i >= 0; i--) {
            d *= 10;
            d += v2[i];
        }
        cout << d << '\n';
    }
    

    return 0;
}
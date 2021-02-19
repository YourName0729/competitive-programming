// iteration
// https://open.kattis.com/problems/fridge
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

int num[10];

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    string s;
    getline(cin, s);
    For (i, s.length()) {
        num[s[i] - '0']++;
    }

    int mn = -1;
    for (int i = 1; i < 10; i++) {
        if (mn == -1 || num[i] < num[mn]) {
            mn = i;
        }
    }

    if (num[mn] == 0) {
        cout << mn << '\n';
    } else if (num[0] <= num[mn] - 1) {
        cout << 1;
        For (i, num[0] + 1) {
            cout << 0;
        }
        cout << '\n';
    } else {
        For (i, num[mn] + 1) {
            cout << mn;
        }
        cout << '\n';
    }
    
    return 0;
}
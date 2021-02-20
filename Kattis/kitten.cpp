//
// https://open.kattis.com/problems/kitten
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

int fa[110];

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int k;
    cin >> k;
    getchar();

    string s;
    while (getline(cin, s)) {
        stringstream ss;
        ss << s;

        int f, c;
        ss >> f;
        if (f == -1)    break;

        while (ss >> c) {
            fa[c] = f;
        }
    }

    while (k != 0) {
        cout << k << ' ';
        k = fa[k];
    }
    cout << '\n';

    return 0;
}

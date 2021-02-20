//
// https://open.kattis.com/problems/statistics
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>
#include <deque>
#include <numeric>
#include <iomanip>

#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;
using namespace std;

const ll INF = 1000000010;
const ll MOD = 1000000007;

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    //fast();

    int n, t = 0;
    int mx, mn;
    while (cin >> n) {
        For (i, n) {
            int tmp;
            cin >> tmp;

            if (i == 0 || tmp > mx) mx = tmp;
            if (i == 0 || tmp < mn) mn = tmp;
        }

        cout << "Case " << ++t << ": " << mn << ' ' << mx << ' ' << mx - mn << '\n';
    }

    return 0;
}

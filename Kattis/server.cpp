// 
// https://open.kattis.com/problems/server
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

    int n, t;
    cin >> n >> t;

    int ans = 0;
    bool fsh = false;
    For (i, n) {
        int tmp;
        cin >> tmp;
        if (!fsh) {
            if (tmp <= t) {
                ans++;
                t -= tmp;
            } else {
                fsh = true;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
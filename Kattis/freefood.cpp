//
// https://open.kattis.com/problems/freefood
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

int n;
bool arr[400];

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin >> n;
    For (i, n) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; j++) {
            arr[j] = true;
        }
    }

    int ans = 0;
    For (i, 400) {
        if (arr[i]) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}

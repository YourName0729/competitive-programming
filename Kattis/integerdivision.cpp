// searching
// https://open.kattis.com/problems/integerdivision
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

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9

using ull = unsigned long long;
using ll = long long;
using namespace std;

map<int, ll> mp;

int main() {

    int n, d;
    cin >> n >> d;
    For (i, n) {
        int tmp;
        cin >> tmp;
        mp[tmp / d]++;
    }

    ll ans = 0;
    Fore (p, mp) {
        if (p.second >= 2) {
            ans += p.second * (p.second - 1) / 2;
        }
    }

    cout << ans << '\n';

    return 0;
}
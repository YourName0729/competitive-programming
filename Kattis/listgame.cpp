//
// https://open.kattis.com/problems/listgame
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define INF 2000000000

using ll = long long;

using namespace std;


int main() {
    //fast;

    ll n;
    cin >> n;

    int ans = 0;
    int cur = 2;
    while (n != 1) {
        if (n % cur == 0) {
            ans++;
            n /= cur;
        } else if (cur > sqrt(n) + 1) {
            ans++;
            break;
        } else {
            cur++;
        }
    }
    cout << ans << '\n';

    return 0;
}
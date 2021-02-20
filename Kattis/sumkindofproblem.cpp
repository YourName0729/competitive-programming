//
// https://open.kattis.com/problems/sumkindofproblem
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

    forcase {
        ll k, n;
        cin >> k >> n;

        ll s1 = n * (n + 1) / 2;
        ll s2 = n * (n + 1) - n;
        ll s3 = s1 * 2;

        cout << k << ' ' << s1 << ' ' << s2 << ' ' << s3 << '\n';
    }

    return 0;
}

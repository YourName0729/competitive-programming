// prime_factoring
// https://open.kattis.com/problems/almostperfect
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

int sqrted(ll n) {
    ll s = sqrt(n);
    if (s * s == n) return s;
    if ((s + 1) * (s + 1) == n) return s + 1;
    return s;
}

ll ds(ll d) {
    ll re = 0;
    for (int i = 1; i <= sqrted(d); i++) {
        if (d % i == 0) {
            re += i;

            if (d / i != i && i != 1) {
                re += d / i;
            }
        }
        
    }
    return re;
}

int main() {
    fast;

    ll n;
    while (cin >> n) {
        ll re = ds(n);
        if (re == n) {
            cout << n << " perfect\n";
        } else if (abs(re - n) <= 2) {
            cout << n << " almost perfect\n";
        } else {
            cout << n << " not perfect\n";
        }
    }

    return 0;
}
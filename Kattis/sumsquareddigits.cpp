//
// https://open.kattis.com/problems/sumsquareddigits
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define forcase int __t;cin>>__t;while(__t--)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;


int main() {
    fast;

    forcase {
        ll k, b, n;
        cin >> k >> b >> n;

        cout << k << ' ';

        int sum = 0;
        while (n) {
            sum += (n % b) * (n % b);
            n /= b;
        }

        cout << sum << '\n';
    }

    return 0;
}

//
// https://open.kattis.com/problems/stararrangements
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define forcase int __t;cin >> __t;while (__t--)
#define For(i, n) for(int i = 0; i < n; i++)

using ll = long long;

using namespace std;

int main() {
    fast;

    int n;
    cin >> n;
    
    cout << n << ":\n";
    for (int i = 2; i <= n / 2 + 1; i++) {
        if ((n - i) % (2 * i - 1) == 0) {
            cout << i << ',' << i - 1 << '\n';
        } else if (n % (2 * i - 1) == 0) {
            cout << i << ',' << i - 1 << '\n';
        }
        if (n % i == 0) {
            cout << i << ',' << i << '\n';
        }
    }

    
    return 0;
}

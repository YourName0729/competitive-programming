//
// https://open.kattis.com/problems/speedlimit
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define forcase int __t;cin >> __t;while (__t--)
#define For(i, n) for(int i = 0; i < n; i++)

using ll = long long;

using namespace std;

int main() {
    fast;

    int n;
    while (cin >> n && n != -1) {
        int sum = 0, prev = 0;
        for (int i = 0; i < n; i++) {
            int m, t;
            cin >> m >> t;
            sum += m * (t - prev);
            prev = t;
        }

        cout << sum << " miles\n";
    }

    
    return 0;
}

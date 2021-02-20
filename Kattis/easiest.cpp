//
// https://open.kattis.com/problems/easiest
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

int ds(int n) {
    int re = 0;
    while (n) {
        re += n % 10;
        n /= 10;
    }
    return re;
}

int main() {
    fast;

    int n;
    while (cin >> n && n != 0) {
        for (int p = 11; p <= 100; p++) {
            if (ds(n * p) == ds(n)) {
                cout << p << '\n';
                break;
            }
        }
    }

    return 0;
}

//
// https://open.kattis.com/problems/modulo
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

bool b[42];

int main() {
    //fast;

    For (i, 10) {
        int n;
        cin >> n;
        b[n % 42] = true;
    }

    int ans = 0;
    For (i, 42) {
        if (b[i]) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}

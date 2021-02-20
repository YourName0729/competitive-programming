//
// https://open.kattis.com/problems/quickestimate
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

int main() {
    //fast;

    forcase {
        string s;
        getline(cin, s);

        cout << s.length() << '\n';
    }

    return 0;
}

//
// https://open.kattis.com/problems/onechicken
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

    int a, b;
    cin >> a >> b;
    if (a < b) {
        if (b - a != 1) {
            cout << "Dr. Chaz will have " << b - a << " pieces of chicken left over!\n";
        } else {
            cout << "Dr. Chaz will have 1 piece of chicken left over!\n";
        }
    } else {
        if (a - b == 1) {
            cout << "Dr. Chaz needs 1 more piece of chicken!\n";
        } else {
            cout << "Dr. Chaz needs " << a - b << " more pieces of chicken!\n";
        }
    }

    return 0;
}

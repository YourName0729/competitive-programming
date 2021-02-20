//
// https://open.kattis.com/problems/numberfun
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>
#include <deque>

#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;
using namespace std;
const ll INF = 1000000010;
const ll MOD = 1000000007;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}



int main() {
    //fast();

    forcase {
        int a, b, c;
        cin >> a >> b >> c;
        if (b > a)  swap(a, b);
        if (a + b == c || a - b == c || b - a == c || a * b == c) {
            cout << "Possible\n";
        } else if (a % b == 0 && a / b == c) {
            cout << "Possible\n";
        } else {
            cout << "Impossible\n";
        }
    }

    return 0;
}

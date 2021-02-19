// logarithm
// https://open.kattis.com/problems/howmanydigits
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

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

double pfx_log[1000010];

int main() {
    //fast();

    for (int i = 2; i < 1000001; i++) {
        pfx_log[i] = pfx_log[i - 1] + log10(i);
    }

    int n;
    while (cin >> n) {
        if (n == 0) {
            cout << 1 << '\n';
        } else {
            cout << int(pfx_log[n]) + 1 << '\n';
        }
    }
    

    return 0;
}
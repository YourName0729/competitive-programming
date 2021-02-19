// iteration
// https://open.kattis.com/problems/hypercube
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <utility>
#include <queue>
#include <iomanip>
#include <deque>
#include <set>

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9
#define EPS 1e-9

using ull = unsigned long long;
using ll = long long;
using namespace std;

ll Pow(int k) {
    if (k == 0) return 1;
    return 2 * Pow(k - 1);
}

int n;
bool arr[100];
ll idx(int cur) {
    if (cur == 0) {
        return arr[cur]? 1 : 0;
    }

    if (arr[cur]) {
        return Pow(cur + 1) - idx(cur - 1) - 1;
    } else {
        return idx(cur - 1);
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n;
    ll idxa, idxb;

    cin >> n;

    For (i, n) {
        char c;
        cin >> c;
        arr[n - i - 1] = (c == '1');
    }
    idxa = idx(n - 1);

    For (i, n) {
        char c;
        cin >> c;
        arr[n - i - 1] = (c == '1');
    }
    idxb = idx(n - 1);

    cout << idxb - idxa - 1 << '\n';
    //cout << idxa << ' ' << idxb << '\n';
    
    return 0;
}
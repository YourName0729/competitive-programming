//
// https://open.kattis.com/problems/lostlineup
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

#define Forcase int __t;cin>>__t;for(int cases=1;cases<=__t;cases++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9
#define LINF 1e18
#define EPS 1e-9

using ull = unsigned long long;
using ll = long long;
using namespace std;

int n;
int arr[110];

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n;
    cin >> n;
    arr[0] = 1;
    For (i, n - 1) {
        int k;
        cin >> k;
        arr[k + 1] = i + 2;
    }

    For (i, n) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    

    return 0;
}

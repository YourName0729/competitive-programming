//
// https://open.kattis.com/problems/kornislav
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

int arr[4];

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    For (i, 4) {
        cin >> arr[i];
    }
    sort(arr, arr + 4);
    cout << arr[0] * arr[2] << '\n';
    
    return 0;
}

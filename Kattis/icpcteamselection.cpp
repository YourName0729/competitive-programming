//
// https://open.kattis.com/problems/icpcteamselection
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

int n;
int arr[310];

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        For (i, 3 * n) {
            cin >> arr[i];
        }

        sort(arr, arr + 3 * n);

        int sum = 0;
        For (i, n) {
            sum += arr[3 * n - 2 - 2 * i];
        }
        cout << sum << '\n';

    }

    
    return 0;
}
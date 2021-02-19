// dp LIS
// https://open.kattis.com/problems/longincsubseq
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

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9
#define EPS 1e-9

using ull = unsigned long long;
using ll = long long;
using namespace std;

int n;
ll arr[100010];
ll dp[100010];

int LIS() {
    if (n == 0) return 0;

    vector<ll> v;
    v.push_back(arr[0]);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > v.back()) {
            v.push_back(arr[i]);
            dp[i] = v.size();
        } else {
            auto ans = lower_bound(v.begin(), v.end(), arr[i]);
            dp[i] = ans - v.begin() + 1;
            *ans = arr[i];
        }
    }

    return v.size();
}

int main() {

    while (cin >> n) {
        For (i, n) {
            cin >> arr[i];
        }


        int ans = LIS();
        cout << ans << '\n';

        stack<int> stk;
        ll ub = 1e12;
        for (int i = n - 1; i >= 0; i--) {
            if (dp[i] == ans && arr[i] < ub) {
                stk.push(i);
                ans--;
                ub = arr[i];
            }
        }
        
        while (!stk.empty()) {
            cout << stk.top() << ' ';
            stk.pop();
        }
        cout << '\n';
    }

    return 0;
}

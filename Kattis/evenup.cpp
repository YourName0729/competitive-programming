//
// https://open.kattis.com/problems/evenup
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

stack<int> stk;
int arr[100010];

int main() {
    //fast();
    
    int n;
    cin >> n;
    For (i, n) {
        cin >> arr[i];
    }

    For (i, n) {
        if (stk.empty() || (stk.top() - arr[i]) % 2 != 0) {
            stk.push(arr[i]);
        } else {
            stk.pop();
        }
    }

    cout << stk.size() << '\n';

    return 0;
}
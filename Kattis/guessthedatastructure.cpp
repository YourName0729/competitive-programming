// case_considering
// https://open.kattis.com/problems/guessthedatastructure
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define INF 2000000000

#define MOD 1000000007

using ll = long long;

using namespace std;

int n;
int op[1010];
int val[1010];

const char* go() {
    bool oks = true, okq = true, okp = true;
    stack<int> stk;
    queue<int> que;
    priority_queue<int> pq;

    For (i, n) {
        if (op[i] == 1) {
            if (oks) stk.push(val[i]);
            if (okq) que.push(val[i]);
            if (okp) pq.push(val[i]);
        } else {
            if (oks) {
                if (stk.empty() || stk.top() != val[i]) {
                    oks = false;
                } else {
                    stk.pop();
                }
            }
            if (okq) {
                if (que.empty() || que.front() != val[i]) {
                    okq = false;
                } else {
                    que.pop();
                }
            }
            if (okp) {
                if (pq.empty() || pq.top() != val[i]) {
                    okp = false;
                } else {
                    pq.pop();
                }
            }
        }
    }

    if (!oks && !okq && !okp)   return "impossible";
    if (oks && !okq && !okp)    return "stack";
    if (!oks && okq && !okp)    return "queue";
    if (!oks && !okq && okp)    return "priority queue";
    return "not sure";
}

int main() {
    //fast;

    
    while (cin >> n) {
        For (i, n) {
            cin >> op[i] >> val[i];
        }

        cout << go() << '\n';
    }
    
 
    return 0;
}
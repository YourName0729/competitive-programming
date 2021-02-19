//
// https://open.kattis.com/problems/backspace
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
#include <numeric>
#include <iomanip>

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



int main() {
    //fast();

    string s;
    stack<char> stk;
    
    cin >> s;
    For (i, s.length()) {
        if (s[i] == '<') {
            stk.pop();
        } else {
            stk.push(s[i]);
        }
    }

    stack<char> stk2;
    while (!stk.empty()) {
        stk2.push(stk.top());
        stk.pop();
    }

    while (!stk2.empty()) {
        cout << stk2.top();
        stk2.pop();
    }
    cout << "\n";

    return 0;
}
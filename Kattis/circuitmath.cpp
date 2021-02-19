//
// https://open.kattis.com/problems/circuitmath
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

using ull = unsigned long long;
using ll = long long;
using namespace std;

bool val[26];

int main() {

    int n;

    cin >> n;
    For (i, n) {
        char c;
        cin >> c;
        val[i] = c == 'T';
    }

    char c;
    string s;
    stringstream ss;
    stack<bool> stk;

    getchar();
    getline(cin, s);
    ss << s;
    while (ss >> c) {
        if ('A' <= c && c <= 'Z') {
            stk.push(val[c - 'A']);
        } else if (c == '*') {
            bool a, b;
            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();
            stk.push(a && b);
        } else if (c == '+') {
            bool a, b;
            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();
            stk.push(a || b);
        } else {
            bool a;
            a = stk.top();
            stk.pop();
            stk.push(!a);
        }
    }

    cout << (stk.top()? 'T' : 'F') << '\n';

    return 0;
}

// string_processing
// https://open.kattis.com/problems/textencryption
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
#include <functional>

#define Forcase int __t;cin>>__t;for(int cases=1;cases<=__t;cases++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9
#define LINF 1e18
#define EPS 1e-9

using ull = unsigned long long;
using ll = long long;
using namespace std;

int k;
string s;
char arr[10010];
bool vst[10010];

void noSpace() {
    stringstream ss;
    string re, tmp;
    ss << s;
    while (ss >> tmp) {
        re += tmp;
    }
    s = re;
}

char upper(char c) {
    if ('A' <= c && c <= 'Z')   return c;
    return c - 'a' + 'A';
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    // cout.tie(NULL);

    while (cin >> k && k != 0) {
        getchar();
        getline(cin, s);
        noSpace();

        For (i, s.length()) {
            vst[i] = false;
        }

        int si = 0, idx = 0, st = 0;
        while (true) {
            if (si == s.length())   break;
            if (vst[idx]) {
                idx += k;
                if (idx >= s.length()) {
                    st++;
                    idx = st;
                }
                continue;
            }

            arr[idx] = s[si];
            vst[idx] = true;
            idx += k;
            si++;
            if (idx >= s.length()) {
                st++;
                idx = st;
            }
        }

        For (i, s.length()) {
            cout << upper(arr[i]);
        }
        cout << '\n';
        
    }
    

    return 0;
}
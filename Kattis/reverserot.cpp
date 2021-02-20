//
// https://open.kattis.com/problems/reverserot
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

string ss = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

int at(char c) {
    if ('A' <= c && c <= 'Z')   return c - 'A';
    if (c == '_')   return 26;
    return 27;
}

int main() {
    //fast();

    int n;
    string s;
    while (cin >> n && n != 0) {
        cin >> s;

        For (i, s.length()) {
            s[i] = ss[(at(s[i]) + n) % ss.length()];
        }
        For (i, s.length()) {
            cout << s[s.length() - i - 1];
        }
        cout << '\n';
    }

    return 0;
}

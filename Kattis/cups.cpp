//
// https://open.kattis.com/problems/cups
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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct S {
    string s;
    int d;
};

S arr[30];

bool isN(string& s) {
    For (i, s.length()) {
        if (!('0' <= s[i] && s[i] <= '9'))  return false;
    }
    return true;
}

bool cmp(S& a, S& b) {
    return a.d < b.d;
}

int main() {
    //fast();
    int n;
    cin >> n;
    getchar();
    For (i, n) {
        string s, a, b;
        stringstream ss;

        getline(cin, s);
        ss << s;
        ss >> a >> b;
        if (isN(a)) {
            arr[i].s = b;
            arr[i].d = stoi(a);
        } else {
            arr[i].s = a;
            arr[i].d = stoi(b) * 2;
        }
    }

    sort(arr, arr + n, cmp);

    For (i, n) {
        cout << arr[i].s << '\n';
    }

    return 0;
}

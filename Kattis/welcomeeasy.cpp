//
// https://open.kattis.com/problems/welcomeeasy
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

string wel = "welcome to code jam";
string s;
int ans;

void go(int wi, int si) {
    if (wi == wel.length() - 1) {
        ans++;
        return;
    }

    for (int i = si + 1; i < s.length(); i++) {
        if (wel[wi + 1] == s[i])
            go(wi + 1, i);
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n;
    cin >> n;
    getchar();
    For (i, n) {
        getline(cin, s);
        ans = 0;
        For (i, s.length()) {
            if (wel[0] == s[i])
                go(0, i);
        }
        cout << "Case #" << i + 1 << ": " << setw(4) << setfill('0') << ans % 1000 << '\n';
    }

    return 0;
}
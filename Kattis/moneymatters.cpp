//
// https://open.kattis.com/problems/moneymatters
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

int n, m;
vector<int> eg[10010];
int val[10010];
bool vst[10010];

int go(int cur) {
    vst[cur] = true;
    int re = val[cur];
    For (i, eg[cur].size()) {
        if (!vst[eg[cur][i]])
            re += go(eg[cur][i]);
    }
    return re;
}

bool can() {
    For (i, n) {
        if (!vst[i]) {
            if (go(i) != 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin >> n >> m;
    For (i, n) {
        cin >> val[i];
    }
    For (i, m) {
        int a, b;
        cin >> a >> b;
        eg[a].push_back(b);
        eg[b].push_back(a);
    }

    if (can()) {
        cout << "POSSIBLE\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
//
// https://open.kattis.com/problems/marblestree
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

int n;

int ball[10010];
int fa[10010];
vector<int> ch[10010];

int dth[10010];
int dball[10010];

void calc(int cur) {
    if (dth[cur] != -1) return;

    For (i, ch[cur].size()) {
        calc(ch[cur][i]);
    }

    dth[cur] = 1;
    dball[cur] = ball[cur];
    For (i, ch[cur].size()) {
        dth[cur] += dth[ch[cur][i]];
        dball[cur] += dball[ch[cur][i]];
    }
}

int dfs(int cur) {
    if (ch[cur].size() == 0) return 0;

    int re = 0;
    For (i, ch[cur].size()) {
        int chneed = dth[ch[cur][i]] - dball[ch[cur][i]];
        dball[ch[cur][i]] += chneed;
        ball[ch[cur][i]] += chneed;
        ball[cur] -= chneed;

        re += dfs(ch[cur][i]) + abs(chneed);
    }

    return re;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    while (cin >> n && n != 0) {
        for (int i = 1; i <= n; i++) {
            fa[i] = ball[i] = 0;
            ch[i].clear();
            dth[i] = dball[i] = -1;
        }

        for (int i = 1; i <= n; i++) {
            int v, m, d, c;
            cin >> v >> ball[i] >> d;

            ch[v].clear();
            For (j, d) {
                cin >> c;
                ch[v].push_back(c);
                fa[c] = v;
            }
        }

        for (int i = 1; i <= n; i++) {
            calc(i);
        }

        int root = -1;
        for (int i = 1; i <= n; i++) {
            if (fa[i] == 0) {
                root = i;
            }
        }

        cout << dfs(root) << '\n';   
    }
    

    return 0;
}
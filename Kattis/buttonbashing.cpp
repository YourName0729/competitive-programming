// greedy
// https://open.kattis.com/problems/buttonbashing
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

#define Forcase int __t;cin>>__t;for(int cases=1;cases<=__t;cases++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9
#define LINF 1e18
#define EPS 1e-9

using ull = unsigned long long;
using ll = long long;
using namespace std;

int n, t;
int bot[20];

int step[4000];

int into(int tar, int bot, int top) {
    if (tar > top)  return top;
    if (tar < bot)  return bot;
    return tar;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    Forcase {
        cin >> n >> t;
        For (i, n) {
            cin >> bot[i];
        }

        For (i, 3601) {
            step[i] = -1;
        }
        step[0] = 0;
        queue<pair<int, int>> que;
        que.push(make_pair(0, 0));

        while (step[t] == -1 && !que.empty()) {
            int cur = que.front().first;
            int stp = que.front().second;
            que.pop();

            //cout << cur << ' ' << stp << '\n';

            For (i, n) {
                int to = into(cur + bot[i], 0, 3600);
                if (step[to] == -1) {
                    step[to] = stp + 1;
                    que.push(make_pair(to, stp + 1));
                }
            }
        }

        for (int i = t; i <= 3600; i++) {
            if (step[i] != -1) {
                cout << step[i] << ' ' << i - t << '\n';
                break;
            }
        }
    }
    
    return 0;
}
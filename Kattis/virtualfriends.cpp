// disjoint_set
// https://open.kattis.com/problems/virtualfriends
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

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

map<string, int> mp;
int n;
int fth[200010];
int sz[200010];

int root(int cur) {
    if (fth[cur] == cur)    return cur;
    fth[cur] = root(fth[cur]);
    return fth[cur];
}

void unn(int a, int b) {
    if (root(a) == root(b)) return;

    int fa = root(a), fb = root(b);
    fth[fa] = fb;
    sz[fb] += sz[fa];
    /*if (rnk[fa] < rnk[fb]) {
        fth[fa] = fb;
        sz[fb] += sz[fa];
    } else if (rnk[fa] > rnk[fb]) {
        fth[fb] = fa;
        sz[fa] = sz[fb];
    } else {
        fth[fa] = fb;
        sz[fb] += sz[fa];
        rnk[fb]++;
    }*/
}

int main() {
    //fast();
    
    forcase {
        mp.clear();
        cin >> n;
        For (i, 2 * n) {
            fth[i] = i;
            sz[i] = 1;
        }

        int id = 0;
        For (i, n) {
            string s1, s2;
            cin >> s1 >> s2;
            if (!mp.count(s1)) {
                mp[s1] = id++;
            }
            if (!mp.count(s2)) {
                mp[s2] = id++;
            }

            unn(mp[s1], mp[s2]);
            cout << sz[root(mp[s1])] << '\n';
        }
    }
    

    return 0;
}
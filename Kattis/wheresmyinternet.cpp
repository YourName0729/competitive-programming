// DFS
// https://open.kattis.com/problems/wheresmyinternet
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define INF 2000000000

#define MOD 1000000007

using ll = long long;

using namespace std;

int n, m;
vector<int> e[200010];
bool vst[200010];

void dfs(int cur) {
    vst[cur] = true;
    For (i, e[cur].size()) {
        if (!vst[e[cur][i]]) {
            dfs(e[cur][i]);
        }
    }
}

int main() {
    fast;

    cin >> n >> m;
    For (i, m) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    
    dfs(1);

    bool conneted = true;
    for (int i = 1; i <= n; i++) {
        if (!vst[i]) {
            cout << i << '\n';
            conneted = false;
        }
    }
    if (conneted) {
        cout << "Connected\n";
    }
 
    return 0;
}
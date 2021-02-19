// Dijkstra
// https://open.kattis.com/problems/shortestpath1
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define INF 2000000000

using ll = long long;

using namespace std;

pair<int, int> point(int a, int b) {
    return make_pair(a, b);
}
/*pair<int, int*> ppoint(int a, int* b) {
    return make_pair(a, b);
}

struct cmp {
    bool operator() (const pair<int, int*>& p1, const pair<int, int*>& p2) {
        return *p1.second < *p2.second;
    }
};*/

int n, m;
vector<pair<int, int>> e[10010];
bool vst[10010];
//priority_queue<pair<int, int*>, vector<pair<int, int*>>, cmp> pq;
int dist[10010];

void dijkstra(int s) {
    //while (!pq.empty()) pq.pop();
    For (i, n) {
        dist[i] = INF;
        vst[i] = false;
    }

    dist[s] = 0;
    For (i, n) {
        //pq.push(ppoint(i, &dist[i]));
    }

    while (true) {
        int cur = -1;
        For (i, n) {
            if (!vst[i]) {
                if (cur == -1 || dist[i] < dist[cur]) {
                    cur = i;
                }
            }
        }

        if (cur == -1 || dist[cur] == INF)  break;
        vst[cur] = true;

        For (i, e[cur].size()) {
            int nb = e[cur][i].first;
            int alt = dist[cur] + e[cur][i].second;
            dist[nb] = min(dist[nb], alt);
        }
    }
}

int main() {
    //fast;

    int q, s;
    while (cin >> n >> m >> q >> s && !(n == 0 && m == 0 && q == 0 && s == 0)) {
        For (i, n) {
            e[i].clear();
        }

        int a, b, w;
        For (i, m) {
            cin >> a >> b >> w;
            e[a].push_back(point(b, w));
        }
        
        dijkstra(s);

        int qq;
        For (i, q) {
            cin >> qq;
            if (dist[qq] == INF) {
                cout << "Impossible\n";
            } else {
                cout << dist[qq] << '\n';
            }
        }
    }

    return 0;
}
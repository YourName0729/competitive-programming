// Floyd-Warshall
// https://open.kattis.com/problems/allpairspath
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>

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

ll n, m;
ll dist[160][160];

void fw() {
    For (k, n) {
        For (i, n) {
            For (j, n) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }  
            }
        }
    }
}

void check() {
    For (i, n) {
        For (j, n) {
            For (k, n) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[k][k] < 0) {
                    dist[i][j] = -INF;
                }
            }
        }   
    }
}

int main() {
    //fast;

    ll q;
    while (cin >> n >> m >> q && !(n == 0 && m == 0 && q == 0)) {
        For (i, n) {
            For (j, n) {
                dist[i][j] = (i == j? 0 : INF);
            }
        }
        For (i, m) {
            ll u, v, w;
            cin >> u >> v >> w;
            dist[u][v] = min(dist[u][v], w);
        }

        fw();
        check();

        For (i, q) {
            ll u, v;
            cin >> u >> v;
            
            if (dist[u][v] == INF) {
                cout << "Impossible\n";
            } else if (dist[u][v] == -INF) {
                cout << "-Infinity\n";
            } else {
                cout << dist[u][v] << '\n';
            }
        }
        cout << '\n';
    }

    return 0;
}

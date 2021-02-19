// Floyd-Warshall
// https://open.kattis.com/problems/slowleak
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ar array

using namespace std;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

int n, m, t;
ll d;
int ct[510];
ll adj[510][510];
ll adj2[510][510];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> t >> d;
    ct[0] = 0;
    for (int i = 1; i <= t; i++) {
        cin >> ct[i], ct[i]--;
    }
    ct[t + 1] = n - 1;
    t = t + 2;
    For (i, n) {
        For (j, n) {
            adj[i][j] = (i == j? 0 : INF);
            
        }
    }
    For (i, m) {
        ll a, b, v;
        cin >> a >> b >> v, a--, b--;
        adj[a][b] = v;
        adj[b][a] = v;
    }
    
    For (k, n) {
        For (i, n) {
            For (j, n) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    // For (i, n) {
    //     For (j, n) {
    //         if (adj[i][j] == INF) {
    //             cout << setw(3) << "inf ";
    //         } 
    //         else {
    //             cout << setw(3) << adj[i][j] << ' ';
    //         }
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    /*if (adj[0][n - 1] == INF) {
        cout << "stuck\n";
        return 0;
    }*/

    For (i, t) {
        For (j, t) {
            if (i == j) {
                adj2[i][j] = 0;
            }
            else if (adj[ct[i]][ct[j]] <= d) {
                adj2[i][j] = adj[ct[i]][ct[j]];
            }
            else {
                adj2[i][j] = INF;
            }
        }
    }

    For (k, t) {
        For (i, t) {
            For (j, t) {
                adj2[i][j] = min(adj2[i][j], adj2[i][k] + adj2[k][j]);
            }
        }
    }

    

    // For (i, t) {
    //     For (j, t) {
    //         if (adj2[i][j] == INF) {
    //             cout << setw(3) << "inf ";
    //         } 
    //         else {
    //             cout << setw(3) << adj2[i][j] << ' ';
    //         }
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    if (adj2[0][t - 1] == INF) {
        cout << "stuck\n";
    }
    else {
        cout << adj2[0][t - 1] << '\n';
    }

    return 0;
}

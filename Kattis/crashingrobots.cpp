// https://open.kattis.com/problems/crashingrobots
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const unsigned ll IINF = 1e18;
const double eps = 1e-12;

map<char, int> mp = {{'N', 1}, {'S', 3}, {'W', 2}, {'E', 0}, {'R', -1}, {'L', 1}};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, p, q;
int arr[110][110];
int xs[110], ys[110], os[110];

int ack[110], acr[110];
char acc[110];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    Forcase {
        cin >> n >> m >> p >> q;
        For (i, n) {
            For (j, m) {
                arr[i][j] = -1;
            }
        }
        For (i, p) {
            cin >> xs[i] >> ys[i], xs[i]--, ys[i]--;
            char c;
            cin >> c;
            os[i] = mp[c];
            arr[xs[i]][ys[i]] = i;
        }

        For (i, q) {
            cin >> ack[i] >> acc[i] >> acr[i];
        }

        try {
            For (i, q) {
                int k = ack[i], r = acr[i];
                char c = acc[i];
                k--;
                if (c == 'F') {
                    For (j, r) {
                        int nx = xs[k] + dx[os[k]];
                        int ny = ys[k] + dy[os[k]];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) throw k;
                        if (arr[nx][ny] != -1) throw make_pair(k, arr[nx][ny]);
                        swap(arr[xs[k]][ys[k]], arr[nx][ny]);
                        xs[k] = nx;
                        ys[k] = ny;
                    }
                }
                else {
                    int l = mp[c];
                    r %= 4;
                    os[k] = (os[k] + r * l + 4) % 4;
                }
            }    
        }
        catch (pair<int, int> p) {
            cout << "Robot " << p.first + 1 << " crashes into robot " << p.second + 1 << "\n";
            continue;
        }
        catch (int d) {
            cout << "Robot " << d + 1 << " crashes into the wall\n";
            continue;
        }
        cout << "OK\n";
    }

    return 0;
}

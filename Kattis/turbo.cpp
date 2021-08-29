// https://open.kattis.com/problems/turbo
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

int sz = 312;
int n;
vector<vector<int>> vec;
int arr[100010];
int bl[100010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    For (i, n) {
        cin >> arr[i], arr[i]--;
        int x = i / sz;
        bl[arr[i]] = x;
        if (x == vec.size()) vec.push_back(vector<int>());
        vec[x].push_back(arr[i]);
    }

    // For (i, n) {
    //     cout << arr[i] << ' ' << bl[i] << '\n';
    // }

    For (i, n) {
        // cout << i << "--\n";
        // For (j, vec.size()) {
        //     For (k, vec[j].size()) {
        //         cout << vec[j][k] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << "--\n";

        if (i % 2 == 0) {
            int u = i / 2;
            int x = bl[u], y = 0;
            For (j, vec[x].size()) {
                if (vec[x][j] == u) {
                    y = j;
                    break;
                }
            }

            int ans = y;
            for (int j = x - 1; j >= 0; --j) {
                ans += vec[j].size();
            }
            cout << ans << '\n';

            vec[x].erase(vec[x].begin() + y);
        }
        else {
            int u = n - 1 - i / 2;
            int x = bl[u], y = 0;
            For (j, vec[x].size()) {
                if (vec[x][j] == u) {
                    y = j;
                    break;
                }
            }

            int ans = vec[x].size() - y - 1;
            for (int j = x + 1; j < vec.size(); ++j) {
                ans += vec[j].size();
            }
            cout << ans << '\n';

            vec[x].erase(vec[x].begin() + y);
        }
    }

    return 0;
}

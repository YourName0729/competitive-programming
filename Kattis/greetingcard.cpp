// number_theory brute_force
// https://open.kattis.com/problems/greetingcard
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-9;

int n;
ar<int, 2> a[100010];
set<ar<int, 2>> st;

int dx[] = {0   , 1118, 1680, 2018, 1680 , 1118 , 0    , -1118, -1680, -2018, -1680, -1118};
int dy[] = {2018, 1680, 1118, 0   , -1118, -1680, -2018, -1680, -1118, 0    , 1118 , 1680};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n)  cin >> a[i][0] >> a[i][1];
    For (i, n)  st.insert(a[i]);
    int ans = 0;
    For (i, n) {
        For (j, 12) {
            int nx = a[i][0] + dx[j];
            int ny = a[i][1] + dy[j];
            if (st.count({nx, ny})) {
                ans++;
            }
        }
    }
    cout << ans / 2 << '\n';


    return 0;
}
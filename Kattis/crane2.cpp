// https://open.kattis.com/problems/crane2
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
const ll IINF = 1e18;
const double eps = 1e-12;
 
int t, n;
int a[10010], b[10010];
 
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ar<int, 2>> ans;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            int idx = 0;
            for (idx = i; idx < n; ++idx) if (a[idx] == i+1) break;
            if (2*idx-i > n) {
                ans.push_back({i+((idx-i+1) % 2)+1, idx+1});
                for (int j = 0; j < (idx-i)/2 + (idx-i) % 2; ++j) swap(a[i + (idx-i+1) % 2 + j], a[(idx+i)/2 + j + 1]);
                idx = (idx+i)/2;
            }
            if (idx != i) {
                ans.push_back({i+1, 2*idx-i});
                for (int j = i; j < idx; ++j) swap(a[j], a[j+idx-i]);
            }
        }
        cout << ans.size() << '\n';
        for (ar<int, 2> i : ans) cout << i[0] << ' ' << i[1] << '\n';
    }
 
    return 0;
}

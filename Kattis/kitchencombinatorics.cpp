// https://open.kattis.com/problems/kitchencombinatorics
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

int R, S, M, D, n;
int a[1010];
vector<int> ss[30], ms[30], ds[30];
set<ar<int, 2>> ban;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> R >> S >> M >> D >> n;
    For (i, R) {
        cin >> a[i];
    }
    For (i, S) {
        int l;
        cin >> l;
        For (j, l) {
            int d;
            cin >> d;
            ss[i].push_back(d);
        }
    }
    For (i, M) {
        int l;
        cin >> l;
        For (j, l) {
            int d;
            cin >> d;
            ms[i].push_back(d);
        }
    }
    For (i, D) {
        int l;
        cin >> l;
        For (j, l) {
            int d;
            cin >> d;
            ds[i].push_back(d);
        }
    }
    For (i, n) {
        int u, v;
        cin >> u >> v, u--, v--;
        ban.insert({min(u, v), max(u, v)});
    }

    try {
        unsigned ll ans = 0;
        For (i, S) {
            For (j, M) {
                if (ban.count({i, S + j})) continue;
                For (k, D) {
                    if (ban.count({i, S + M + k}) || ban.count({S + j, S + M + k})) continue;
                    set<int> st;
                    for (auto v : ss[i]) st.insert(v);
                    for (auto v : ms[j]) st.insert(v);
                    for (auto v : ds[k]) st.insert(v);

                    unsigned ll cur = 1;
                    for (auto v : st) {
                        if (cur > IINF / a[v - 1]) throw 1;
                        cur *= a[v - 1];
                    }
                    ans += cur;
                    if (ans > (unsigned ll)1e18 || ans < 0) throw 1;
                }
            }
        }    
        cout << ans << '\n';
    }
    catch (int d) {
        cout << "too many\n";
    }
    

    return 0;
}

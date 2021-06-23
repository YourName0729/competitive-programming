// https://open.kattis.com/problems/orders
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

struct D {
    int add = -1, prv = -1;
    bool vst = 0;
    bool amb = 0;
};

int n;
int a[110];
D dp[30010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n) cin >> a[i];
    dp[0].vst = 1;
    For (i, n) {
        for (int j = 0; j + a[i] <= 30000; j++) {
            int tar = j + a[i];
            if (dp[j].vst) {
                if (dp[j].amb || dp[tar].vst) {
                    dp[tar].amb = 1;
                }
                else {
                    dp[tar].prv = j;
                    dp[tar].add = i + 1;
                }
                dp[tar].vst = 1;
            }
        }
    }

    // For (i, 100) {
    //     if (dp[i].vst && !dp[i].amb) {
    //         cout << i << ": ";
    //         for (auto v : dp[i].vec) {
    //             cout << v << ' ';
    //         }
    //         cout << '\n';
    //     }
    // }

    Forcase {
        int c;
        cin >> c;
        if (!dp[c].vst) cout << "Impossible\n";
        else if (dp[c].amb) cout << "Ambiguous\n";
        else {
            stack<int> stk;
            while (dp[c].prv != -1) {
                stk.push(dp[c].add);
                c = dp[c].prv;
            }
            while (stk.size()) {
                cout << stk.top() << ' ';
                stk.pop();
            }
            cout << '\n';
        }
    }

    return 0;
}

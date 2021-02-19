// DFS bit_operation
// https://open.kattis.com/problems/pebblesolitaire2
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

vector<bool> dp;

int ans = 23;

void show(int cur) {
    For (i, 23) {
        if (cur & (1 << i)) {
            cout << 'o';
        }
        else {
            cout << '-';
        }
    }
}

void dfs(int cur) {
    if (dp[cur])    return;
    dp[cur] = 1;
    // show(cur);
    // cout << '\n';
    int cnt = 0;
    For (i, 23) if (cur & (1 << i)) cnt++;
    ans = min(ans, cnt);
    For (i, 23 - 1) {
        if ((cur & (3 << i)) != (3 << i))   continue;
        if (i != 0 && (cur & (1 << (i - 1))) == 0) {
            // show(cur);
            // cout << " 1> ";
            // show(cur ^ (7 << (i - 1)));
            // cout << '\n';
            dfs(cur ^ (7 << (i - 1)));
        }
        if (i != 23 - 2 && (cur & (1 << (i + 2))) == 0) {
            // show(cur);
            // cout << " 2> ";
            // show(cur ^ (7 << i));
            // cout << '\n';
            dfs(cur ^ (7 << i));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        dp.resize(1 << 23, false);
        ans = 23;

        int s = 0;
        For (i, 23) {
            char c;
            cin >> c;
            s |= (1 << i) * (c == 'o');
        }

        dfs(s);
        
        cout << ans << '\n';
    }

    return 0;
}
// https://open.kattis.com/problems/geppetto
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

int n, m, ans = 0;
vector<int> arr[20];

void dfs(int i, int ban) {
    if (i == n) {
        ++ans;
        return;
    }

    dfs(i + 1, ban);
    if ((ban & (1 << i)) == 0) {
        int tmp = ban;
        for (auto v : arr[i]) {
            tmp |= 1 << v;
        }
        dfs(i + 1, tmp);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    For (i, m) {
        int u, v;
        cin >> u >> v, --u, --v;
        if (u > v) swap(u, v);
        arr[u].push_back(v);
    }

    dfs(0, 0);

    cout << ans << '\n';

    return 0;
}

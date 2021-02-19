// iteration
// https://open.kattis.com/problems/missinggnomes
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

set<int> st;
int a[100010];

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    For (i, m) {
        cin >> a[i];
        st.insert(a[i]);
    }

    int i = 0, cur = 1;
    while (cur <= n) {
        while (i < m && a[i] < cur) {
            cout << a[i] << '\n';
            i++;
        }
        if (!st.count(cur)) {
            cout << cur << '\n';
        }
        cur++;
    }

    while (i < m) {
        cout << a[i] << '\n';
        i++;
    }

    return 0;
}
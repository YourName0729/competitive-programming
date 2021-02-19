// iteration
// https://open.kattis.com/problems/birds
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

int l, d, n;
vector<int> a;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> l >> d >> n;
    For (i, n) {
        int d;
        cin >> d;
        a.push_back(d);
    }
    a.push_back(6 - d);
    a.push_back(l - 6 + d);
    sort(a.begin(), a.end());
    //For (i, a.size()) cout << a[i] << ' ';
    cout << '\n';
    int ans = 0;
    for (int i = 0; i < a.size() - 1; i++) {
        ans += (a[i + 1] - a[i]) / d - 1;
    }
    cout << ans << '\n';


    return 0;
}
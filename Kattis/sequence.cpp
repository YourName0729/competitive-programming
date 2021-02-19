// greedy
// https://open.kattis.com/submissions/6747384
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
const ll INF = 1e18;
const double eps = 1e-9;


int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    ll n;
    cin >> n;
    vector<int> ans;
    ll d = 1;
    while (d <= n) {
        ans.push_back(d);
        d *= 2;
    }

    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e << ' ';
    }
    

    return 0;
}
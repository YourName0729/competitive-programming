// prime_factoring
// https://open.kattis.com/problems/candydivision
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<ll> ans;
    ll n;
    cin >> n;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) {
                ans.push_back(i);
            }
            else {
                ans.push_back(i);
                ans.push_back(n / i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto e : ans)  cout << e - 1 << ' ';
    cout << '\n';

    return 0;
}
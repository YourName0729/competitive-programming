//
// https://open.kattis.com/problems/reseto
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
const double eps = 1e-12;

vector<bool> vec;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, k;
    cin >> n >> k;
    vec.resize(n + 1, 0);
    for (ll i = 2; i <= n; i++) {
        if (!vec[i]) {
            if (k == 1) {
                cout << i;
                return 0;
            }
            k--;
            for (ll j = i * i; j <= n; j += i) {
                if (!vec[j]) {
                    if (k == 1) {
                        cout << j;
                        return 0;
                    }
                    k--;
                    vec[j] = 1;
                }
            }
        }
    }

    return 0;
}
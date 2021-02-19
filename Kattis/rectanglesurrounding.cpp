// brute_force
// https://open.kattis.com/problems/rectanglesurrounding
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

int n;
int x1[100], ya[100], x2[100], y2[100];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n && n) {
        For (i, n)  cin >> x1[i] >> ya[i] >> x2[i] >> y2[i];
        int ans = 0;
        For (i, 501) {
            For (j, 501) {
                int cnt = 0;
                For (k, n) {
                    if (x1[k] <= i && ya[k] <= j && i < x2[k] && j < y2[k]) cnt++;
                }
                if (cnt != 0)   ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
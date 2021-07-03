// https://open.kattis.com/problems/arithmeticdecoding
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

int n, d;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> d;
    char c;
    string s;
    cin >> c >> c >> s;
    ll tar = 0;
    for (auto c : s) {
        tar <<= 1;
        tar += c - '0';
    }
    tar <<= (3 * n - s.length());

    ll l = 0, r = (1 << (3 * n));
    For (i, n) {
        ll mid = l + ((d * (r - l)) >> 3);
        if (tar >= mid) {
            cout << 'B';
            l = mid;
        }
        else {
            cout << 'A';
            r = mid;
        }
    }

    return 0;
}

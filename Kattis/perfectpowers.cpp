// number_theory
// https://open.kattis.com/problems/perfectpowers
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

    ll n;
    bool neg;
    while (cin >> n && n != 0) {
        neg = (n < 0);
        n = abs(n);
        ll cur = 2;
        while (1) {
            if (cur * cur > n) {
                cout << "1\n";
                break;
            }
            if (n % cur == 0) {
                ll nn = n, cnt = 0;
                bool flg = 0;
                while (1) {
                    if (nn == 1) {
                        flg = 1;
                        break;
                    }
                    if (nn % cur != 0) break;
                    nn /= cur;
                    cnt++;
                }
                if (flg && (cnt % 2 == 1 || !neg)) {
                    cout << cnt << '\n';
                    break;
                }
            }
            cur++;
        }
    }
    


    return 0;
}

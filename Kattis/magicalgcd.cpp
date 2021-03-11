// https://open.kattis.com/problems/magicalgcd
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
 
int n;
ll a[100010];
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    Forcase {
        cin >> n;
        For (i, n) cin >> a[i];
        ll ans = 0;
        map<ll, int> mp;
        For (i, n) {
            map<ll, int> mp2;
            if (!mp.count(a[i])) {
                mp2[a[i]] = i;
                ans = max(ans, a[i]);
            }
            for (auto p : mp) {
                ll g = p.first;
                int idx = p.second;
                ans = max(ans, (i - idx + 1) * __gcd(a[i], g));
                ll g2 = __gcd(a[i], g);
                if (mp2.count(g2)) mp2[g2] = min(mp2[g2], idx);
                else   mp2[g2] = idx;
            }
            mp = mp2;
        }
        cout << ans << '\n';
    }
    
    return 0;
}

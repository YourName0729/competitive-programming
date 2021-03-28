// .
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ar array
 
using namespace std;
using namespace __gnu_pbds;
 
template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;
 
const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-12;

int n;
int a, b;
string s;

int f(int l, int r, char cl, char cr) {
    //cout << l << ' ' << r << '\n';
    int re = MOD;
    int len = r - l + 1;
    if (len % 2 == 0) {
        re = min(re, len / 2 * (a + b) - b + b * (cl == 'J') + b * (cr == 'C'));
        re = min(re, (len / 2) * (a + b) - a + a * (cl == 'C') + a * (cr == 'J'));
    }
    else { 
        re = min(re, (len / 2) * (a + b) + b * (cl == 'J') + a * (cr == 'J'));
        re = min(re, (len / 2) * (a + b) + a * (cl == 'C') + b * (cr == 'C'));
    }
    re = min(re, b * (cl == 'J') + a * (cr == 'J'));
    re = min(re, a * (cl == 'C') + b * (cr == 'C'));
    return re;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int cases = 0;
    Forcase {
        cases++;
        cin >> a >> b;
        cin >> s;
        
        n = s.length();
        int ans = 0;
        For (i, n - 1) {
            if (s[i] == 'C' && s[i + 1] == 'J') ans += a;
            if (s[i] == 'J' && s[i + 1] == 'C') ans += b;
        }
        //cout << "cur " << ans << '\n';

        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                int j = i;
                while (j + 1 < n && s[j + 1] == '?') j++;
                char l = ' ', r = ' ';
                if (i != 0) l = s[i - 1];
                if (j != n - 1) r = s[j + 1];
                ans += f(i, j, l, r);
                i = j;
            }
        }

        cout << "Case #" << cases << ": " << ans << '\n';
    }

    return 0;
}

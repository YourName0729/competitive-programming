// dp
// https://open.kattis.com/submissions/6769688
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

int n, m, c;
bool vst[10000010];

string s, s1, s2;
bool dp[5010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s >> s1 >> s2;
    dp[0] = 1;
    for (int i = 1; i <= s1.length(); i++) {
        dp[i] = (s[i - 1] == s1[i - 1]) && dp[i - 1];
    }
    for (int i = 1; i <= s2.length(); i++) {
        dp[0] = (s[i - 1] == s2[i - 1]) && dp[0];
        for (int j = 1; j <= s1.length(); j++) {
            char cs = s[i + j - 1], cs1 = s1[j - 1], cs2 = s2[i - 1];
            if (cs == cs1 && cs == cs2) {
                dp[j] = dp[j] || dp[j - 1];
            }
            else if (cs == cs1) {
                dp[j] = dp[j - 1];
            }
            else if (cs == cs2) {
                dp[j] = dp[j];
            }
            else {
                dp[j] = 0;
            }
        }
    }

    if (dp[s1.length()]) {
        cout << "yes\n";
    }
    else {
        cout << "no\n";
    }

    return 0;
}

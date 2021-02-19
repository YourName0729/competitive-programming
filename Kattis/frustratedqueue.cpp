// dp
// https://open.kattis.com/problems/frustratedqueue
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

string s;
int dp[1010][510];

int f(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    if (x == 0) {
        return y == s.length() / 2 && (s[0] == '.' || s[0] == '(');
    }

    int ans = 0;
    if ((s[x] == '.' || s[x] == ')') && y < s.length() / 2) {
        ans += f(x - 1, y + 1);
    }
    if ((s[x] == '.' || s[x] == '(') && s.length() - x - 1 - y < y) {
        ans += f(x - 1, y);
    }
    ans %= 1000000;
    return dp[x][y] = ans;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    while (getline(cin, s)) {
        For (i, s.length()) For (j, s.length() / 2 + 1) dp[i][j] = -1;
        cout << f(s.length() - 1, 0) << '\n';
    }


    return 0;
}
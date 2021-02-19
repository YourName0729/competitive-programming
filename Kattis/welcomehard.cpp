// string_processing dp
// https://open.kattis.com/problems/welcomehard
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

string wel = "welcome to code jam";
string s;
int dp[510][19];


int f(int x, int y) {
    if (y == -1)    return 1;
    if (x == -1)    return 0;
    if (dp[x][y] != -1) return dp[x][y];
    if (s[x] != wel[y]) {
        return dp[x][y] = f(x - 1, y);
    }
    else {
        return dp[x][y] = (f(x - 1, y - 1) + f(x - 1, y)) % 10000;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    getline(cin, s);
    For (tt, t) {
        cout << "Case #" << tt + 1 << ": ";
        getline(cin, s);
        For (i, s.length()) {
            For (j, wel.length()) {
                dp[i][j] = -1;
            }
        }
        
        cout << setw(4) << setfill('0') << f(s.length() - 1, wel.length() - 1) << '\n';
    }

    return 0;
}
// greedy
// https://open.kattis.com/problems/reduction
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

int n, m;
//int dp[100010];

int solve(int A, int B) {
    // dp[m] = 0;
    // for (int i = m + 1; i <= n; i++) {
    //     dp[i] = dp[i - 1] + A;
    //     if (i / 2 >= m) dp[i] = min(dp[i], dp[i / 2] + B);
    // }
    // return dp[n];
    int ans = 0;
    int nn = n;
    while (nn / 2 >= m) {
        ans += min(A * (nn - nn / 2), B);
        nn /= 2;
    }
    return ans + A * (nn - m);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    string s;
    cin >> t;
    For (tt, t) {
        cout << "Case " << tt + 1 << '\n';
        int l;
        cin >> n >> m >> l;
        vector<pair<int, string>> ans;
        For (i, l) {
            cin >> s;
            string name;
            int A, B, col, dot;
            For (i, s.length()) {
                if (s[i] == ':')    col = i;
                if (s[i] == ',')    dot = i;
            }
            name = s.substr(0, col);
            A = stoi(s.substr(col + 1, dot - col - 1));
            B = stoi(s.substr(dot + 1, s.length() - dot - 1));
            ans.push_back({solve(A, B), name});
        }

        sort(ans.begin(), ans.end());
        for (auto p : ans) {
            cout << p.second << ' ' << p.first << '\n';
        }
    }

    return 0;
}
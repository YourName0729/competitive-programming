// https://open.kattis.com/problems/heritage
#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;
//using namespace __gnu_pbds;

//template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-12;

vector<int> build(string& T) {
    vector<int> F(T.length());
    int p = F[0] = -1;
    for (int i = 1; i < T.length(); i++) {
        while (p != -1 && T[p + 1] != T[i]) p = F[p];
        if (T[p + 1] == T[i])   p++;
        F[i] = p;
    }
    return F;
}

vector<int> match(string& S, string& T, vector<int>& F) {
    vector<int> re;
    int p = -1;
    For (i, S.length()) {
        while (p != -1 && T[p + 1] != S[i]) p = F[p];
        if (T[p + 1] == S[i]) p++;
        if (p == T.length() - 1) {
            re.push_back(i - p);
            //cout << i - p << ' ';
            p = F[p];
        }
    }
    return re;
}

int n;
string S;
string T[10010];
int a[10010];
vector<int> F[10010];
ll dp[40];
vector<int> ed[40];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> S;
    For (i, n)  cin >> T[i] >> a[i];
    For (i, n) {
        F[i] = build(T[i]);
    }
    For (i, n) {
        vector<int> ans = match(S, T[i], F[i]);
        for (auto j : ans) {
            //cout << i << ' ';
            ed[j + T[i].length()].push_back(i);
        }
        //cout << '\n';
    }
    dp[0] = 1;
    for (int i = 1; i <= S.length(); i++) {
        for (auto j : ed[i]) {
            dp[i] = (dp[i] + a[j] * dp[i - T[j].length()] % MOD) % MOD;
        }
    }
    cout << dp[S.length()];
    

    return 0;
}

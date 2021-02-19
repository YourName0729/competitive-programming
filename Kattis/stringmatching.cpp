// KMP
// https://open.kattis.com/problems/stringmatching
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

string S, T;
int F[2000010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (getline(cin, T)) {
        getline(cin, S);
        int p = F[0] = -1;
        for (int i = 1; i < T.length(); i++) {
            while (p != -1 && T[p + 1] != T[i]) p = F[p];
            if (T[p + 1] == T[i])   p++;
            F[i] = p;
        }

        // For (i, T.length()) cout << F[i] << ' ';
        // cout << '\n';

        p = -1;
        For (i, S.length()) {
            while (p != -1 && T[p + 1] != S[i]) p = F[p];
            if (T[p + 1] == S[i]) p++;
            if (p == T.length() - 1) {
                cout << i - p << ' ';
                p = F[p];
            }
        }
        cout << '\n';
    }

    return 0;
}
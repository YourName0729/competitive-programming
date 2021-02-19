// KMP
// https://open.kattis.com/problems/powerstrings
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

string S;
int F[2000010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> S && S != ".") {
        int p = F[0] = -1;
        for (int i = 1; i < S.length(); i++) {
            while (p != -1 && S[p + 1] != S[i]) p = F[p];
            if (S[p + 1] == S[i])   p++;
            F[i] = p;
        }

        // For (i, S.length())  cout << F[i] << ' ';
        // cout << '\n';

        int ans = S.length() - F[S.length() - 1] - 1;
        if (S.length() % ans) {
            cout << "1\n";
        }
        else {
            cout << S.length() / ans << '\n';
        }
    }

    return 0;
}

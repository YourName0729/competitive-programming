// easy
// https://open.kattis.com/problems/divideby100
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

    string a, b;
    cin >> a >> b;
    int sft = b.length() - 1;
    if (sft >= a.length()) {
        cout << "0.";
        For (i, sft - a.length()) {
            cout << '0';
        }
        while (a.back() == '0') a.pop_back();
        cout << a << '\n';
    }
    else {
        while (sft && a.back() == '0') {
            sft--;
            a.pop_back();
        }
        if (sft == 0) {
            cout << a << '\n';
        }
        else {
            For (i, a.length() - sft) {
                cout << a[i];
            }
            cout << '.';
            For (i, sft) {
                cout << a[a.length() - sft + i];
            }
            cout << '\n';
        }
    }

    return 0;
}
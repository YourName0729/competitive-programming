// https://open.kattis.com/problems/primaryarithmetic
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
const unsigned ll IINF = 1e18;
const double eps = 1e-12;

int arr[30], brr[30];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string a, b;
    while (cin >> a >> b && !(a == "0" && b == "0")) {
        For (i, 20) arr[i] = brr[i] = 0;
        For (i, a.size()) {
            arr[a.size() - i - 1] = a[i] - '0';
        }
        For (i, b.size()) {
            brr[b.size() - i - 1] = b[i] - '0';
        }

        int ans = 0;
        For (i, 20) {
            if (arr[i] + brr[i] >= 10) {
                ++ans;
                ++arr[i + 1];
            }
        }

        if (ans >= 2) {
            cout << ans << " carry operations.\n";
        }
        else if (ans > 0) {
            cout << ans << " carry operation.\n";
        }
        else {
            cout << "No carry operation.\n";
        }
    }

    return 0;
}

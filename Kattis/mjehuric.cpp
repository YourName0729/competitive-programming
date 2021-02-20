// https://open.kattis.com/problems/mjehuric
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

int n = 5;
int a[10];

bool ok() {
    For (i, n)  if (a[i] != i + 1)  return 0;
    return 1;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    For (i, n)  cin >> a[i];
    while (!ok()) {
        For (i, n - 1) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                For (i, n) {
                    cout << a[i] << ' ';
                }
                cout << '\n';
            }
        }
    }
    
    return 0;
}

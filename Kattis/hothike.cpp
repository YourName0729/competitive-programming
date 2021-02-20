//
// https://open.kattis.com/problems/hothike
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

int n;
int a[100];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    int m = MOD, d = 0;
    For (i, n)  cin >> a[i];
    for (int i = 0; i < n - 2; i++) {
        if (max(a[i], a[i + 2]) < m) {
            m = max(a[i], a[i + 2]);
            d = i + 1;
        }
    }

    cout << d << ' ' << m << '\n';


    return 0;
}

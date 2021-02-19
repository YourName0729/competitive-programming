// divide_and_conquer
// https://open.kattis.com/problems/excursion
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

int a[1000010];

ll ms(int l, int r) {
    if (l == r) return 0;
    int mid = (l + r) / 2;
    ll re = ms(l, mid) + ms(mid + 1, r);
    int cnts[3] = {0, 0, 0};
    // for (int i = l; i <= mid; i++) {
    //     cout << a[i];
    // }
    // cout << '-';
    // for (int i = mid + 1; i <= r; i++) {
    //     cout << a[i];
    // }
    // cout << '\n';
    for (int i = l; i <= mid; i++) {
        cnts[a[i]]++;
    }
    for (int i = mid + 1; i <= r; i++) {
        //cout<<"a["<<i<<"]="<<a[i]<<'\n';
        for (int j = a[i] + 1; j <= 2; j++) {
            re += cnts[j];
        }
        //cnts[a[i]]++;
    }
    //cout << l << ' ' << r << ' ' << re << '\n';
    return re;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;
    For (i, s.length()) {
        a[i] = s[i] - '0';
    }

    cout << ms(0, s.length() - 1) << '\n';

    return 0;
}
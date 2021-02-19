// divided_and_conquer
// https://open.kattis.com/problems/divisible
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

int n;
ll a[50010], D;
map<ll, int> mp;

ll ms(int l, int r) {
    if (l == r) return a[l] % D == 0;
    int mid = (l + r) / 2;
    ll re = ms(l, mid) + ms(mid + 1, r);
    mp.clear();
    ll sum = 0;
    for (int i = mid + 1; i <= r; i++) {
        sum = (sum + a[i]) % D;
        mp[sum]++;
    }
    sum = 0;
    for (int i = mid; i >= l; i--) {
        sum = (sum + a[i]) % D;
        re += mp[(D - sum) % D];
    }
    //cout << l << ' ' << r << ' ' << re << '\n';
    return re;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        cin >> D >> n;
        For (i, n)  cin >> a[i], a[i] %= D;
        cout << ms(0, n - 1) << '\n';
    }

    return 0;
}
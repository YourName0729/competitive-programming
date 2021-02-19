// divide_and_conquer
// https://open.kattis.com/problems/subseqhard
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

int n;
int a[1000010];
map<int, int> mp;

ll ms(int l, int r) {
    if (l == r) return a[l] == 47;
    int mid = (l + r) / 2;
    ll re = ms(l, mid) + ms(mid + 1, r);
    mp.clear();
    ll s = 0;
    for (int i = mid + 1; i <= r; i++) {
        s += a[i];
        mp[s]++;
    }
    s = 0;
    for (int i = mid; i >= l; i--) {
        s += a[i];
        re += mp[47 - s];
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        cin >> n;
        For (i, n)  cin >> a[i];
        cout << ms(0, n - 1) << '\n';
    }

    return 0;
}
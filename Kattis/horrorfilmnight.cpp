// iteration
// https://open.kattis.com/problems/horrorfilmnight
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

bool a[1000010], b[1000010];

int go() {
    int re = 0;
    bool pa = 0, pb = 1;
    For (i, 1000001) {
        if (!a[i] && !b[i]) continue;
        if ((!pa && !a[i]) || (!pb && !b[i]))   continue;
        re++;
        pa = a[i], pb = b[i];
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    For (i, n) {
        int d;
        cin >> d;
        a[d] = 1;
    }
    cin >> n;
    For (i, n) {
        int d;
        cin >> d;
        b[d] = 1;
    }

    int ans = go();
    For (i, 1000001)    swap(a[i], b[i]);
    ans = max(ans, go());
    cout << ans;
    
    
    return 0;
}
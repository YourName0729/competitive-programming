// https://open.kattis.com/problems/juggler
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;
template<class key, class value, class cmp = std::less<key>> using indexed_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;

int n;
int arr[100010];
indexed_set<int> st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    For (i, n) {
        int x;
        cin >> x, --x;
        arr[x] = i;
        st.insert(i);
    }

    ll ans = n;
    int b = 0, sz = n;
    for (int i = 0; i < n; ++i) {
        int odr = st.order_of_key(arr[i]);
        ans += min((b - odr + sz) % sz, (odr - b + sz) % sz);
        // cout << (b - odr + sz) % sz << " or " << (odr - b + sz) % sz << '\n';
        st.erase(arr[i]);
        --sz;
        if (i != n - 1) b = odr % sz;
    }
    cout << ans << '\n';

    return 0;
}
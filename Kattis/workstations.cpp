// sorting_and_searching
// https://open.kattis.com/problems/workstations
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

int n, m;
ar<int, 2> a[300010];
multiset<int> st;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    For (i, n) {
        cin >> a[i][0] >> a[i][1];
        a[i][1] += a[i][0];
    }

    sort(a, a + n);

    int ans = 0;
    For (i, n) {
        //cout << a[i][0] << ' ' << a[i][1] << '\n';
        while (!st.empty() && *st.begin() + m < a[i][0])    st.erase(st.begin());
        // if (st.empty() || *st.begin() > a[i][0]) {
        //     //ans++;
        // }
        if (!st.empty() && *st.begin() <= a[i][0]) {
            ans++;
            //cout << "use " << *st.begin() << '\n';
            st.erase(st.begin());
        }
        st.insert(a[i][1]);
    }

    cout << ans << '\n';

    return 0;
}

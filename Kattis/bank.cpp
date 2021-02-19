// greedy
// https://open.kattis.com/problems/bank
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

int n, T;
ar<int, 2> a[10010];

bool cmp(ar<int, 2> a, ar<int, 2> b) {
    return a[1] < b[1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> T;
    For (i, n)  cin >> a[i][0] >> a[i][1];
    sort(a, a + n, cmp);

    priority_queue<int> pq;
    int avb = n - 1, ans = 0;
    for (int t = T; t >= 0; t--) {
        //cout << "t " << t << '\n';
        while (avb >= 0 && a[avb][1] >= t) {
            //cout << "push " << a[avb][0] << ' ' << a[avb][1] << '\n';
            pq.push(a[avb][0]);
            avb--;
        }
        if (!pq.empty()) {
            //cout << "add " << pq.top() << '\n';
            ans += pq.top();
            pq.pop();
        }
    } 

    cout << ans << '\n';

    return 0;
}
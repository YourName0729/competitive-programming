// sorting_and_searching
// https://open.kattis.com/problems/continuousmedian
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

priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;

void trim() {
    if (pq1.size() > pq2.size()) {
        pq2.push(pq1.top());
        pq1.pop();
    }
    if (pq2.size() > pq1.size() + 1) {
        pq1.push(pq2.top());
        pq2.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        while (!pq1.empty())    pq1.pop();
        while (!pq2.empty())    pq2.pop();

        int n;
        ll ans = 0;
        cin >> n;
        For (i, n) {
            int d;
            cin >> d;
            if (pq2.empty() || d <= pq2.top()) {
                pq1.push(d);
            }
            else {
                pq2.push(d);
            }
            trim();
            if (pq1.size() == pq2.size()) {
                ans += (pq1.top() + pq2.top()) / 2;
            }
            else {
                ans += pq2.top();
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
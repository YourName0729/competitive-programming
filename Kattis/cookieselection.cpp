// sorting_and_searching
// https://open.kattis.com/problems/cookieselection
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

priority_queue<ll> pq1;
priority_queue<ll, vector<ll>, greater<ll>> pq2;

void flex() {
    while (pq1.size() > pq2.size()) {
        pq2.push(pq1.top());
        pq1.pop();
    }
    while (pq2.size() >= pq1.size() + 2) {
        pq1.push(pq2.top());
        pq2.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    

    string s;
    while (getline(cin, s)) {
        if (s == "#") {
            //cout << pq1.size() << ' ' << pq2.size() << '\n';
            cout << pq2.top() << '\n';
            pq2.pop();
        }
        else {
            stringstream ss;
            ss << s;
            ll d;
            ss >> d;
            if (!pq1.empty() && d <= pq1.top()) {
                pq1.push(d);
            }
            else if (!pq2.empty() && d >= pq2.top()) {
                pq2.push(d);
            }
            else {
                pq1.push(d);
            }
        }
        flex();
    }

    return 0;
}
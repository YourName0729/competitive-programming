// sorting_and_searching
// https://open.kattis.com/problems/dyslectionary
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

vector<string> a;

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    bool flg = 1;
    string s;
    while (getline(cin, s)) {
        if (!flg)   cout << '\n';
        flg = 0;
        a.clear();
        reverse(s.begin(), s.end());
        a.push_back(s);
        while (getline(cin, s) && s != "") {
            reverse(s.begin(), s.end());
            a.push_back(s);
        }
        sort(a.begin(), a.end());
        int mx = 0;
        for (string& e : a) mx = max(mx, (int)e.length());
        for (string& e : a) {
            reverse(e.begin(), e.end());
            cout << setw(mx) << e << '\n';
        }
        //cout << '\n';
    }

    return 0;
}
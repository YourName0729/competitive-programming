// https://open.kattis.com/problems/engineeringenglish
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
const unsigned ll IINF = 1e18;
const double eps = 1e-12;

int n;
int arr[100010];

string lower(string s) {
    for (char& c : s) {
        if ('A' <= c && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }
    return s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    set<string> st;
    string s;
    while (cin >> s) {
        if (st.count(lower(s))) {
            cout << ". ";
        }
        else {
            cout << s << ' ';
            st.insert(lower(s));
        }
    }

    return 0;
}

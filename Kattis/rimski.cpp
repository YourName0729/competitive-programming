// https://open.kattis.com/problems/rimski
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-12;

set<char> s1 = {'X', 'L', 'C'};
set<char> s2 = {'I', 'V'};

map<int, string> mp = {
    {10, "X"},
    {20, "XX"},
    {30, "XXX"},
    {40, "XL"},
    {50, "L"},
    {60, "LX"},
    {70, "LXX"},
    {80, "LXXX"},
    {90, "XC"},
    {1, "I"},
    {2, "II"},
    {3, "III"},
    {4, "IV"},
    {5, "V"},
    {6, "VI"},
    {7, "VII"},
    {8, "VIII"},
    {9, "IX"}
};

string toroman(int d) {
    string re;
    if (d >= 10) {
        re = mp[d / 10 * 10];
    }
    if (d % 10 != 0) {
        re += mp[d % 10];
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;
    
    sort(s.begin(), s.end());

    int ans = MOD;
    for (int i = 1; i < 100; i++) {
        string cur = toroman(i);
        string cpy = cur;
        sort(cur.begin(), cur.end());
        if (cur == s) {
            cout << cpy << '\n';
            return 0;
        }
    }

    return 0;
}

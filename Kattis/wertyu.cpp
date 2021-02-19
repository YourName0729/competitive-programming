//
// https://open.kattis.com/problems/wertyu
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

map<char, char> mp = {
    {'1', '`'},
    {'2', '1'},
    {'3', '2'},
    {'4', '3'},
    {'5', '4'},
    {'6', '5'},
    {'7', '6'},
    {'8', '7'},
    {'9', '8'},
    {'0', '9'},
    {'-', '0'},
    {'=', '-'},
    {'W', 'Q'},
    {'E', 'W'},
    {'R', 'E'},
    {'T', 'R'},
    {'Y', 'T'},
    {'U', 'Y'},
    {'I', 'U'},
    {'O', 'I'},
    {'P', 'O'},
    {'[', 'P'},
    {']', '['},
    {'\\', ']'},
    {'S', 'A'},
    {'D', 'S'},
    {'F', 'D'},
    {'G', 'F'},
    {'H', 'G'},
    {'J', 'H'},
    {'K', 'J'},
    {'L', 'K'},
    {';', 'L'},
    {'\'', ';'},
    {'X', 'Z'},
    {'C', 'X'},
    {'V', 'C'},
    {'B', 'V'},
    {'N', 'B'},
    {'M', 'N'},
    {',', 'M'},
    {'.', ','},
    {'/', '.'},
    {' ', ' '}
};

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    while (getline(cin, s)) {
        for (char c : s) {
            cout << mp[c];
        }
        cout << '\n';
    }

    return 0;
}
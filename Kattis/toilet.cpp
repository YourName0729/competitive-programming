//
// https://open.kattis.com/problems/toilet
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

string s;

int p1() {
    int ans = 0;
    char prv = s[0];
    for (int i = 1; i < s.length(); i++) {
        if (prv == 'U') {
            ans += 1;
        }
        else if (s[i] == 'U') {
            ans += 2;
        }
        prv = 'D';
    }
    return ans;
}

int p2() {
    int ans = 0;
    char prv = s[0];
    for (int i = 1; i < s.length(); i++) {
        if (prv == 'D') {
            ans += 1;
        }
        else if (s[i] == 'D') {
            ans += 2;
        }
        prv = 'U';
    }
    return ans;
}

int p3() {
    int ans = 0;
    char prv = s[0];
    for (int i = 1; i < s.length(); i++) {
        if (prv != s[i])    ans++;
        prv = s[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    cout << p2() << '\n' << p1() << '\n' << p3() << '\n';

    return 0;
}
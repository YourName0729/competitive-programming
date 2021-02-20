//
// https://open.kattis.com/problems/heimavinna
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
const ll INF = 1e18;

string s;

int go(int l, int r) {
    stringstream ss;
    ss << s.substr(l, r - l + 1);
    int re = 0;
    ss >> re;
    char c;
    if (ss >> c) {
        int re2;
        ss >> re2;
        return re2 - re + 1;
    }
    return 1;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    getline(cin, s);
    int n = s.length();

    int prv = 0, ans = 0;
    For (i, n) {
        if (s[i] == ';') {
            ans += go(prv, i - 1);
            prv = i + 1;
        }
    }
    ans += go(prv, n - 1);

    cout << ans << '\n';


    return 0;
}

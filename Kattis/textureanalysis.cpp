//
// https://open.kattis.com/problems/textureanalysis
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
const double eps = 1e-12;

bool ok(vector<int>& vec) {
    if (vec.size() == 0)    return 1;
    int d = vec[1] - vec[0];
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec[i + 1] - vec[i] != d)   return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    int cnt = 0;
    while (cin >> s && s != "END") {
        cnt++;
        vector<int> vec;
        For (i, s.length()) {
            if (s[i] == '*')    vec.push_back(i);
        }
        if (ok(vec)) {
            cout << cnt << ' ' << "EVEN\n";
        }
        else {
            cout << cnt << ' ' << "NOT EVEN\n";
        }
    }

    return 0;
}
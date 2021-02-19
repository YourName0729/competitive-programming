//
// https://open.kattis.com/problems/bottledup
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

string str[] = {
    "single",
    "double",
    "triple"
};

int ok(int a) {
    if (a <= 20)    return 1;
    if (a <= 40 && a % 2 == 0)  return 2;
    if (a <= 60 && a % 3 == 0)  return 3;
    return 0;
}

bool ok(int a, int b, int c) {
    int x = ok(a), y = ok(b), z = ok(c);
    if (x && y && z) {
        if (a) cout << str[x - 1] << ' ' << a / x << '\n';
        if (b) cout << str[y - 1] << ' ' << b / y << '\n';
        if (c) cout << str[z - 1] << ' ' << c / z << '\n';
        return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int s, v, w;
    cin >> s >> v >> w;
    int av = MOD, aw = MOD;
    For (i, s + 1) {
        if (i % v == 0 && (s - i) % w == 0) {
            if (i / v + (s - i) / w < av + aw) {
                av = i / v, aw = (s - i) / w;
            }
        }
    }
    if (av == MOD) {
        cout << "Impossible";
    }
    else
        cout << av << ' ' << aw;

    return 0;
}
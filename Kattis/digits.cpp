// simulation
// https://open.kattis.com/problems/digits
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
const double eps = 1e-9;

int dig(int d) {
    //if (d == 0) return 1;
    int re = 0;
    while (d != 0) {
        re++;
        d /= 10;
    }
    return re;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    while (getline(cin, s) && s != "END") {
        int d = s.length();
        For (i, s.length()) {
            if (s[i] == '0')    d--;
            else break;
        }

        if (s == "1") {
            cout << "1\n";
            continue;
        }
        else if (s == "0") {
            cout << "2\n";
            continue;
        }

        int ans = 1, prv = d;
        //cout << d << ' ';
        while (1) {
            d = dig(d);
            //cout << d << ' ';
            ans++;
            if (prv == d)   break;
            prv = d;
        }
        //cout << '\n';
        cout << ans << '\n';
    }

    return 0;
}
// string_processing
// https://open.kattis.com/problems/tautology
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

string str;

bool eval(int s, int val, int& nxt) {
    if ('a' <= str[s] && str[s] <= 'z') {
        nxt = s + 1;
        return val & (1 << (str[s] - 'p'));
    }

    if (str[s] == 'N') {
        return !eval(s + 1, val, nxt);
    }
    if (str[s] == 'K') {
        int nxt1;
        bool b1 = eval(s + 1, val, nxt1);
        bool b2 = eval(nxt1, val, nxt);
        return b1 && b2;
    }
    if (str[s] == 'A') {
        int nxt1;
        bool b1 = eval(s + 1, val, nxt1);
        bool b2 = eval(nxt1, val, nxt);
        return b1 || b2;
    }
    if (str[s] == 'C') {
        int nxt1;
        bool b1 = eval(s + 1, val, nxt1);
        bool b2 = eval(nxt1, val, nxt);
        return !b1 || b2;
    }
    //if (str[s] == 'E') {
        int nxt1;
        bool b1 = eval(s + 1, val, nxt1);
        bool b2 = eval(nxt1, val, nxt);
        return b1 == b2;
    //}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> str && str != "0") {
        bool flg = 0;
        int e;
        for (int i = 0; i < (1 << 5); i++) {
            if (!eval(0, i, e)) {
                cout << "not\n";
                flg = 1;
                break;
            }
        }
        if (!flg) {
            cout << "tautology\n";
        }
    }
    
    return 0;
}
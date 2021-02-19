// case_considering
// https://open.kattis.com/problems/thinkingofanumber
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

int n, m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n && n != 0) {
        vector<int> div;
        int l = 0, r = 50001;
        For (i, n) {
            string s1, s2;
            int d;
            cin >> s1 >> s2 >> d;
            if (s1[0] == 'l') {
                r = min(r, d);
            }
            else if (s1[0] == 'g') {
                l = max(l, d);
            }
            else {
                div.push_back(d);
            }
        }

        if (r == 50001) {
            cout << "infinite\n";
        }
        else {
            vector<int> ans;
            for (int i = l + 1; i <= r - 1; i++) {
                bool flg = 0;
                for (auto e : div) {
                    if (i % e != 0) {
                        flg = 1;
                        break;
                    }
                }
                if (!flg) {
                    ans.push_back(i);
                }
            }
            if (ans.size() == 0) {
                cout << "none\n";
            }
            else {
                for (auto e : ans) {
                    cout << e << ' ';
                }
                cout << '\n';
            }
        }

    }

    return 0;
}
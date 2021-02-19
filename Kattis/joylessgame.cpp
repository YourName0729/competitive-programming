// case_considering game
// https://open.kattis.com/problems/joylessgame
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


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        string s;
        cin >> s;

        if (s.front() == s.back()) {
            int cnt = 0;
            For (i, s.length()) {
                if (s[i] == s.front())  cnt++;
            }
            int d = s.length() - (2 * cnt - 1);
            if (d % 2 == 0) {
                cout << "Bash\n";
            }
            else {
                cout << "Chikapu\n";
            }
        }
        else {
            int cnt = 0;
            char w = s.front();
            For (i, s.length()) {
                if (s[i] == w) {
                    cnt++;
                    w = (w == s.front()? s.back() : s.front());
                }
            }
            int d = s.length() - cnt;
            if (d % 2 == 0) {
                cout << "Bash\n";
            }
            else {
                cout << "Chikapu\n";
            }
        }
    }

    return 0;
}
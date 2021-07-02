// https://open.kattis.com/problems/prva
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const unsigned ll IINF = 1e18;
const double eps = 1e-12;

int n, m;
char arr[30][30];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    vector<string> vec;
    cin >> n >> m;
    For (i, n) For (j, m) cin >> arr[i][j];
    For (i, n) {
        string s;
        For (j, m) {
            if (arr[i][j] != '#') s += arr[i][j];
            else {
                if (s.length() >= 2) {
                    vec.push_back(s);
                }
                s.clear();
            }
        }
        if (s.length() >= 2) {
            vec.push_back(s);
        }
    }

    For (i, m) {
        string s;
        For (j, n) {
            if (arr[j][i] != '#') s += arr[j][i];
            else {
                if (s.length() >= 2) {
                    vec.push_back(s);
                }
                s.clear();
            }
        }
        if (s.length() >= 2) {
            vec.push_back(s);
        }
    }

    sort(vec.begin(), vec.end());
    cout << vec.front() << '\n';

    return 0;
}

// case_considering
// https://open.kattis.com/problems/arithmetic
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

bool a[700010];
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;
    for (int i = s.length() - 1, j = 0; i >= 0; i--, j += 3) {
        int d = s[i] - '0';
        a[j] = d & 1;
        a[j + 1] = d & 2;
        a[j + 2] = d & 4;
    }
    n = 3 * s.length();

    // For (i, n)  cout << a[i];
    // cout << '\n';

    vector<int> ans;
    for (int i = 0; i < n; i += 4) {
        int d = a[i] * 1 + a[i + 1] * 2 + a[i + 2] * 4 + a[i + 3] * 8;
        ans.push_back(d);
    }

    while (ans.size() >= 2 && ans.back() == 0)  ans.pop_back();

    for (int i = ans.size() - 1; i >= 0; i--) {
        if (ans[i] >= 10) {
            cout << (char)(ans[i] + 'A' - 10);
        }
        else {
            cout << ans[i];
        }
    }
    cout << '\n';

    return 0;
}
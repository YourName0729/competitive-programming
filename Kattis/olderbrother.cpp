// prime_factoring
// https://open.kattis.com/problems/olderbrother
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

int n;

vector<pair<int, int>> prime_factor(int d) {
    vector<pair<int, int>> re;
    int cur = 2;
    double ub = sqrt(d);
    while (d != 1) {
        if (cur > ub + 1) {
            re.pb({d, 1});
            break;
        }
        if (d % cur == 0) {
            int itr = 0;
            while (d % cur == 0) {
                itr++;
                d /= cur;
            }
            re.pb({cur, itr});
            ub = sqrt(d);
        }
        cur++;
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    auto ans = prime_factor(n);
    if (ans.size() == 1) {
        cout << "yes\n";
    }
    else {
        cout << "no\n";
    }

    return 0;
}
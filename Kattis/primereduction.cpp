// prime_factoring
// https://open.kattis.com/problems/primereduction
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

int n;

ar<int, 2> solve(int a, int step) {
    auto fac = prime_factor(a);
    if (fac.size() == 1 && fac.front().second == 1)    return {a, step};
    int sum = 0;
    for (auto p : fac) {
        sum += p.first * p.second;
    }
    return solve(sum, step + 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n && n != 4) {
        ar<int, 2> ans = solve(n, 0);
        cout << ans[0] << ' ' << ans[1] + 1 << '\n';
    }

    return 0;
}
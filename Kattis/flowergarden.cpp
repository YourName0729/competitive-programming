// greedy simulation
// https://open.kattis.com/problems/flowergarden
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
double D;
vector<ar<int, 2>> a;
bool np[20010];

double dist(int i) {
    int j = i + 1;
    int dx = a[i][0] - a[j][0];
    int dy = a[i][1] - a[j][1];
    return sqrt(dx * dx + dy * dy);
    //return abs(dx) + abs(dy);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    np[1] = 1;
    for (int i = 2; i * i <= 20000; i++) {
        if (!np[i]) {
            for (int j = i * i; j <= 20000; j += i) {
                np[j] = 1;
            }
        }
    }

    Forcase {
        cin >> n >> D;
        a.clear();
        a.push_back({0, 0});
        For (i, n) {
            int u, v;
            cin >> u >> v;
            a.push_back({u, v});
        }
        int i = 0;
        for (i = 0; i < n; i++) {
            if (dist(i) <= D) {
                D -= dist(i);
            }
            else break;
        }
        while (np[i])   i--;
        cout << i << '\n';
    }


    return 0;
}
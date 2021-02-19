// case_considering
// https://open.kattis.com/problems/rockpaperscissors
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

int n, k;
int a[110], w[110];
map<string, int> mp = {{"paper", 0}, {"scissors", 1}, {"rock", 2}};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    bool fst = 1;

    while (cin >> n && n != 0) {
        if (!fst)   cout << '\n';
        fst = 0;
        cin >> k;
        For (i, n + 1)  a[i] = w[i] = 0;
        For (i, k * n * (n - 1) / 2) {
            int p1, m1, p2, m2;
            string s1, s2;
            cin >> p1 >> s1 >> p2 >> s2;
            m1 = mp[s1], m2 = mp[s2];
            if (m1 == m2)   continue;
            a[p1]++, a[p2]++;
            //cout << m1 << ' ' << m2 << '\n';
            if ((m1 + 1) % 3 == m2) w[p2]++;
            else w[p1]++;
        }

        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) cout << "-\n";
            else {
                cout << fixed << setprecision(3) << (double)w[i] / (double)a[i] << '\n';
            }
        }   
    }
    

    return 0;
}
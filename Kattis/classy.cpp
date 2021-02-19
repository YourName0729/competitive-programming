// sorting
// https://open.kattis.com/problems/classy
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

int n;
pair<int, string> a[110];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        cin >> n;
        string cls, s;
        For (i, n) {
            cin >> a[i].second >> cls >> s;
            a[i].second.pop_back();
            cls.push_back('-');

            vector<int> vec;
            //int prv = 0;
            For (j, cls.length()) {
                if (cls[j] == '-') {
                    //s = cls.substr(prv, j - prv);
                    if (cls[j - 3] == 'p')   vec.push_back(-1);
                    else if (cls[j - 1] == 'e') vec.push_back(0);
                    else    vec.push_back(1);
                    //prv = j + 1;
                }
            }

            int sum = 0, w = 1048576;
            for (int j = vec.size() - 1; j >= 0; j--) {
                sum += vec[j] * w;
                w /= 4;
            }
            a[i].first = sum;
        }

        sort(a, a + n);

        For (i, n) {
            cout << a[i].second << '\n';
        }
        cout << "==============================\n";
    }

    return 0;
}
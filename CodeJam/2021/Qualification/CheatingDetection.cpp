// .
// only pass visible 1
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ar array
 
using namespace std;
using namespace __gnu_pbds;
 
template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;
 
const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-12;

int n;
vector<bool> a[110];
double S[110], sus[110];
double Q[10010];

double ok(double q) {
    double re = 0;
    For (i, 100) {
        re += 1 / (1 + exp(-S[i] + q));
    }
    return re / 100.0;
}

void bs(int idx) {
    int cnt = 0;
    For (i, 100) {
        cnt += a[i][idx];
    }
    double p = cnt / 100.0;

    double l = -3, r = 3;
    while (r - l > 0.01) {
        double mid = (l + r) / 2;
        if (ok(mid) < p) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    Q[idx] = l;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T, P;
    cin >> T >> P;
    For (tt, T) {
        For (i, 100) {
            char c;
            a[i].clear();
            For (j, 10000) {
                cin >> c;
                a[i].push_back(c == '1');
            }
        }
    
        For (i, 100) {
            int cnt = 0;
            For (j, 10000) {
                cnt += a[i][j];
            }
            double p = cnt / 10000.0;
            S[i] = log(p / 1 - p);
        }

        For (i, 10000) {
            bs(i);
        }

        For (i, 100) {
            sus[i] = 0;
            For (j, 10000) {
                if (a[i][j]) {
                    double p = 1 / (1 + exp(-S[i] + Q[j]));
                    sus[i] += pow(1 - p, 2);  
                }
            }
        }

        int ans = 0;
        For (i, 100) {
            if (sus[i] > sus[ans]) ans = i;
        }
        cout << "Case #" << tt + 1 << ": " << ans + 1 << '\n';
    }

    return 0;
}

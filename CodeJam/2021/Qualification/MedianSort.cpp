// .
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

int T, N, Q;
int a[60];

int res(vector<int> vec) {
    sort(vec.begin(), vec.end());
    For (i, 3) cout << vec[i] << ' ';
    cout << '\n';
    int d;
    cin >> d;
    return d;
}

void ins(int idx, int v) {
    for (int i = N - 2; i >= idx; i--) {
        swap(a[i], a[i + 1]);
    }
    a[idx] = v;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> T >> N >> Q;
    For (tt, T) {
        int re = res({1, 2, 3});
        if (re == 1) a[0] = 2, a[1] = 1, a[2] = 3;
        if (re == 2) a[0] = 1, a[1] = 2, a[2] = 3;
        if (re == 3) a[0] = 1, a[1] = 3, a[2] = 2;

        for (int i = 3; i < N; i++) {
            int l = 0, r = i - 1;
            re = res({a[l], a[r], i + 1});
            if (re == a[l]) {
                ins(0, i + 1);
            }
            else if (re == a[r]) {
                ins(i, i + 1);
            }
            else {
                while (l + 1 < r) {
                    int cl = (2 * l + r) / 3, cr = (l + 2 * r) / 3;
                    re = res({a[cl], a[cr], i + 1});
                    if (re == a[cl]) {
                        r = cl;
                    }
                    else if (re == a[cr]) {
                        l = cr;
                    }
                    else {
                        l = cl, r = cr;
                    }
                }
                ins(r, i + 1);
            }
        }
        For (i, N) {
            cout << a[i] << " \n"[i == N - 1];
        }
        int d;
        cin >> d;
    }

    return 0;
}

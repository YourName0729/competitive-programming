// greedy
// https://open.kattis.com/problems/purplerain
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

int a[100010];
int ans = 0, ansl, ansr;

void update(int d, int l, int r) {
    if (d > ans)    ans = d, ansl = l, ansr = r;
    else if (d == ans) {
        if (l < ansl || (l == ansl && r < ansr)) {
            ansl = l, ansr = r;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    //cin >> n;
    string s;
    cin >> s;
    For (i, s.length()) {
        a[i] = (s[i] == 'R'? 1 : -1);
        //cout << a[i] << ' ';
    }
    //cout << '\n';

    int cnt = 0, l = 0;
    For (i, s.length()) {
        cnt += a[i];
        if (cnt < 0) {
            cnt = 0, l = i + 1;
        }
        else {
            update(cnt, l, i);
        }
    }

    cnt = 0, l = 0;
    For (i, s.length()) {
        cnt += -1 * a[i];
        if (cnt < 0) {
            cnt = 0, l = i + 1;
        }
        else {
            update(cnt, l, i);
        }
    }

    cout << ansl + 1 << ' ' << ansr + 1 << '\n';

    return 0;
}
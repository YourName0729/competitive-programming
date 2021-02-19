// segment_tree
// https://open.kattis.com/problems/supercomputer
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
const ll INF = 1e18;
const double eps = 1e-9;

int n;
int a[4000010];

void update(int i, int bot, int top, int tar) {
    if (bot == top) {
        a[i] = (a[i] + 1) % 2;
        //cout << "[" << bot << ' ' << top << "] " << a[i] << '\n';
        return;
    }

    int mid = (bot + top) / 2, cl = 2 * i, cr = cl + 1;
    if (tar <= mid) {
        update(cl, bot, mid, tar);
    }
    else {
        update(cr, mid + 1, top, tar);
    }
    a[i] = a[cl] + a[cr];
    //cout << "[" << bot << ' ' << top << "] " << a[i] << '\n';
}

int query(int i, int bot, int top, int l, int r) {
    if (bot == l && top == r) {
        return a[i];
    }

    int mid = (bot + top) / 2, cl = 2 * i, cr = cl + 1;
    if (r <= mid) {
        return query(cl, bot, mid, l, r);
    }
    else if (mid + 1 <= l) {
        return query(cr, mid + 1, top, l, r);
    }
    return query(cl, bot, mid, l, mid) + query(cr, mid + 1, top, mid + 1, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> n >> q;
    
    while (q--) {
        char c;
        cin >> c;
        if (c == 'F') {
            int d;
            cin >> d;
            update(1, 1, n, d);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }


    return 0;
}
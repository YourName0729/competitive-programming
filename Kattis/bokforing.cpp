// segment_tree
// https://open.kattis.com/problems/bokforing
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;

int n, q;
int seg[4000100];

void push(int i, int l, int r, int q, int v) {
    if (l == r) {
        seg[i] = v;
        return;
    }

    int mid = (l + r) / 2;
    int cl = 2 * i, cr = cl + 1;
    if (seg[i] != -1) {
        seg[cl] = seg[i];
        seg[cr] = seg[i];
        seg[i] = -1;
    }

    if (q <= mid) push(cl, l, mid, q, v);
    else    push(cr, mid + 1, r, q, v);
}

int quest(int i, int l, int r, int q) {
    if (seg[i] != -1)   return seg[i];
    int mid = (l + r) / 2;
    if (q <= mid) return quest(2 * i, l, mid, q);
    else    return quest(2 * i + 1, mid + 1, r, q);
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    while (q--) {
        string s;
        cin >> s;
        if (s == "SET") {
            int a, b;
            cin >> a >> b;
            push(1, 1, n, a, b);
        }
        else if (s == "RESTART") {
            int d;
            cin >> d;
            seg[1] = d;
            //push(1, 1, n, 1, n, d);
        }
        else {
            int d;
            cin >> d;
            cout << quest(1, 1, n, d) << '\n';
        }
    }


    return 0;
}
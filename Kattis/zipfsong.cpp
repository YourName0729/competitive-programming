// sorting
// https://open.kattis.com/problems/zipfsong
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

int n, m;

struct D {
    ll t, idx;
    string s;
};
D arr[50010];

bool cmp(D& a, D& b) {
    ll aa = a.t * a.idx, bb = b.t * b.idx;
    if (aa != bb) {
        return aa < bb;
    }

    return a.idx > b.idx;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    For (i, n) {
        cin >> arr[i].t >> arr[i].s;
        arr[i].idx = i + 1;
    }

    sort(arr, arr + n, cmp);

    for (int i = n - 1; i >= n - m; i--) {
        cout << arr[i].s << '\n';
    }


    return 0;
}
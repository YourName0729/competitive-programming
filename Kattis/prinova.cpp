// optimization
// https://open.kattis.com/problems/prinova
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

ll n, l, r;
ll a[110];
ll ans = 0;

ll d(ll at) {
    ll re = MOD;
    For (i, n) {
        re = min(re, abs(at - a[i]));
    }
    return re;
}

void check(ll mid) {
    if (mid < l || r < mid) return;
    if (d(mid) > d(ans))    ans = mid;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n)  cin >> a[i];
    sort(a, a + n);

    cin >> l >> r;
    if (l % 2 == 0) l++;
    if (r % 2 == 0) r--;

    ans = 0;
    if (d(l) < d(r)) ans = r;
    else    ans = l;

    For (i, n - 1) {
        ll mid = (a[i] + a[i + 1]) / 2;
        if (mid % 2 == 0) {
            check(mid - 1);
            check(mid + 1);
        }
        else {
            check(mid);
        }
        //cout << mid << ' ' << d(mid) << '\n';
        //if (l <= mid && mid <= r && d(mid) > d(ans))    ans = mid;
    }
    cout << ans;

    return 0;
}
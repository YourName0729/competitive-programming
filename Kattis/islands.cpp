//
// https://open.kattis.com/problems/islands
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

int a[20];

bool is(int l, int r) {
    int b = max(a[l - 1], a[r + 1]);
    //cout << l << ' ' << r << ' ' << b << '\n';
    for (int i = l; i <= r; i++) {
        if (a[i] <= b)  return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        int t;
        cin >> t;
        For (i, 12) cin >> a[i];
        int ans = 0;
        for (int i = 1; i <= 10; i++) {
            for (int j = i; j <= 10; j++) {
                if (is(i, j)) {
                    ans++;
                }
            }
        }
        cout << t << ' ' << ans << '\n';
    }

    return 0;
}
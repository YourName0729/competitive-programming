// https://open.kattis.com/problems/diversecookies
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 2147483647;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    ll n, a[3];
    cin >> n;
    For (i, 3) cin >> a[i];
    sort(a, a + 3);
    if (a[2] > a[1] + a[0] + n) {
        cout << 2 * (a[0] + a[1]) + n;
    }
    else cout << a[0] + a[1] + a[2];

    return 0;
}
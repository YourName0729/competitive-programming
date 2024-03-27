// https://open.kattis.com/problems/stirlingsapproximation
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

int n;

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);

    while (cin >> n && n) {
        double s = 0;
        for (int i = 1; i <= n; ++i) s += log(i);
        double ans = 
            exp(s - n * log(n) + n)
            / sqrt(2 * acos(-1) * n);
        cout << fixed << setprecision(16) << ans << '\n';
    }

    return 0;
}
//
// https://open.kattis.com/problems/eulersnumber
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

set<int> vec;

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    double d = 1;
    double ans = 1;
    for (int i = 1; i <= n; i++) {
        d /= i;
        ans += d;
    } 
    cout << fixed << setprecision(18) << ans << '\n';


    return 0;
}
//
// https://open.kattis.com/problems/pascal
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

int solve(int n) {
    for (int i = 2; i < n; i++) {
        if (i * i > n)  break;
        if (n % i == 0) return n - n / i;
    }
    return n - 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    cout << solve(n);

    return 0;
}
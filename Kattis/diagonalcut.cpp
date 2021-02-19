// gcd
// https://open.kattis.com/problems/diagonalcut
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

ll GCD(ll a, ll b) {
    if(b) while((a %= b) && (b %= a));
    return a + b;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    ll a, b;
    cin >> a >> b;
    ll g = GCD(a, b);
    if (a / g % 2 == 0 || b / g % 2 == 0) {
        cout << "0\n";
    }
    else {
        cout << g << '\n';
    }

    return 0;
}
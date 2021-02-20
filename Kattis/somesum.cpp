//
// https://open.kattis.com/problems/somesum
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



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << "Either";
    }
    else if (n % 4 == 0) {
        cout << "Even";
    }
    else {
        cout << "Odd";
    }

    return 0;
}

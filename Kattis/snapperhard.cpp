//
// https://open.kattis.com/problems/snapperhard
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

int n, k;

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    For (i, t) {
        cin >> n >> k;
        if (((k + 1) % ((1 << n)) == 0)) {
            cout << "Case #" << i + 1 << ':' << " ON\n";
        }
        else {
            cout << "Case #" << i + 1 << ':' << " OFF\n";
        }
    }
    

    return 0;
}
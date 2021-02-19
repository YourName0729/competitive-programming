//
// https://open.kattis.com/problems/candlebox
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
    
    int d, r, t;
    cin >> d >> r >> t;
    for (int i = 3 + d; i < 2000; i++) {
        int agr = i, agt = i - d;
        int cr = (agr + 1) * agr / 2 - 6;
        int ct = (agt + 1) * agt / 2 - 3;
        if (abs(cr - r) == abs(ct - t)) {
            cout << abs(cr - r) << '\n';
            break;
        } 
    }

    return 0;
}
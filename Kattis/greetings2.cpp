//
// https://open.kattis.com/problems/greetings2
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

    string s;
    cin >> s;
    cout << 'h';
    For (i, s.size() * 2 - 4)   cout << 'e';
    cout << 'y';
    
    return 0;
}

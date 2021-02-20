// 
// https://open.kattis.com/problems/bossbattle
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define forcase int __t;cin >> __t;while (__t--)
#define For(i, n) for(int i = 0; i < n; i++)

using ll = long long;

using namespace std;

int main() {
    fast;

    int n;
    cin >> n;

    int b = 1;
    int at = n;
    while (3 + (b - 1) * 2 < at) {
        b++;
        at++;
    }
    cout << b << '\n';

    
    return 0;
}
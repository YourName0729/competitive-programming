// dp game
// https://open.kattis.com/problems/amultiplicationgame
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

ll n;
map<ll, bool> mp;

bool win(ll d) {
    if (mp.count(d))    return mp[d];
    if (9 * d >= n) {
        //cout << d << " 1\n";
        return mp[d] = 1;
    }
    for (int i = 2; i <= 9; i++) {
        if (!win(i * d)) {
            //cout << d << " 1";
            return mp[d] = 1;
        }
    }
    //cout << d << " 0";
    return mp[d] = 0;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    
    while (cin >> n) {
        mp.clear();
        if (win(1)) {
            cout << "Stan wins.\n";
        }
        else {
            cout << "Ollie wins.\n";
        }
    }

    return 0;
}
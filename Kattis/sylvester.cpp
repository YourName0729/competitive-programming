//
// https://open.kattis.com/problems/sylvester
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

int val(ll x, ll y, ll n) {
    if (n == 1) return 1;

    ll n2 = n / 2;
    if (x < n2 && y < n2) {
        return val(x, y, n2);
    }
    if (x < n2) {
        return val(x, y - n2, n2);
    }
    if (y < n2) {
        return val(x - n2, y, n2);
    }
    return -val(x - n2, y - n2, n2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    Forcase {
        ll n;
        ll x, y;
        int w, h;
        cin >> n >> x >> y >> w >> h;
        For (j, h) {
            For (i, w) {
                cout << val(x + i, y + j, n) << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
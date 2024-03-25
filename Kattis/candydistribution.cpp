// https://open.kattis.com/problems/candydistribution
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

// extended gcd
// by pin3da
// ref https://github.com/pin3da/Programming-contest/blob/master/solved/kattis/2018%20NAIPC%20Practice%20Contest%2001/Candy%20Distribution/solution.cc

void ext_euclid(long long a, long long b, long long &x, long long &y, long long &g) {
  x = 0, y = 1, g = b;
  long long m, n, q, r;
  for (long long u = 1, v = 0; a != 0; g = a, a = r) {
    q = g / a, r = g % a;
    m = x - u * q, n = y - v * q;
    x = u, y = v, u = m, v = n;
  }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    // given K, C
    // find X, Y s.t. (K * X) + 1 = C * Y
    //              KX - CY = 1
    //      if gcd(K, C) = 1

    ll a, b, x, y, g;
    Forcase {
        cin >> a >> b;
        if (a == 1 && b == 1) {
            cout << 2 << '\n';
            continue;
        }
        if (b == 1) {
            cout << a + 1 << '\n';
            continue;
        }
        ext_euclid(a, b, x, y, g);
        if (g != 1) cout << "IMPOSSIBLE\n";
        else if (y > 0) {
            cout << y << '\n';
        }
        else {
            // cout << y / a - 1 << ' ' << (y / a) * a << '\n';
            cout << y + (-y / a + 1) * a << '\n';
        }
    }

    return 0;
}
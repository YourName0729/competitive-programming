// https://open.kattis.com/problems/primes2
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const unsigned ll IINF = 1e18;
const double eps = 1e-12;

string s;

ll tod(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    return c - 'A' + 10;
}

ll tod(ll b) {
    ll re = 0;
    for (auto c : s) {
        re *= b;
        re += tod(c);
    }
    return re;
}


bool prime(ll d) {
    if (d < 2) return 0;
    for (ll i = 2; i * i <= d; ++i) {
        if (d % i == 0) return 0;
    }
    return 1;
}

bool legal(function<bool(char)> func) {
    for (auto c : s) {
        if (!func(c)) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    Forcase {
        
        cin >> s;
        int m = 0, n = 0;
        if (legal([](char c) { return c == '0' || c == '1'; }) ) {
            ++m;
            if (prime(tod((ll)2))) ++n;
        }
        if (legal([](char c) { return '0' <= c && c <= '7'; })) {
            ++m;
            if (prime(tod((ll)8))) ++n;
        }
        if (legal([](char c) { return '0' <= c && c <= '9'; })) {
            ++m;
            if (prime(tod((ll)10))) ++n;
        }
        ++m;
        if (prime(tod((ll)16))) ++n;

        if (n == 0) {
            cout << "0/1\n";
        }
        else {
            int g = __gcd(m, n);
            m /= g, n /= g;
            cout << n << '/' << m << '\n';
        }
    }


    return 0;
}

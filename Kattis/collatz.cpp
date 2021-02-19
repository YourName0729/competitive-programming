// simulation
// https://open.kattis.com/problems/collatz
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-9;

vector<ll> va, vb;

void nxt(ll& a) {
    if (a % 2 == 0) a /= 2;
    else a = 3 * a + 1;
}

void make(ll n, vector<ll>& vec) {
    do {
        vec.push_back(n);
        if (n == 1) return;
        nxt(n);
    } while (1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, m;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        va.clear();
        vb.clear();
        make(n, va);
        make(m, vb);

        ll ans = 1;
        while (!va.empty() && !vb.empty() && va.back() == vb.back()) {
            ans = va.back();
            va.pop_back();
            vb.pop_back();
        }
        cout << n << " needs " << va.size() << " steps, ";
        cout << m << " needs " << vb.size() << " steps, ";
        cout << "they meet at " << ans << '\n';
    }

    

    return 0;
}
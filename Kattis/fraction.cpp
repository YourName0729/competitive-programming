// https://open.kattis.com/problems/fraction
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

struct Frac {
    ll p, q;

    Frac(ll a, ll b) {
        p = a, q = b;
        trim();
    }

    Frac(const vector<int>& vec) {
        q = 1, p = vec.back();
        for (int i = vec.size() - 2; i >= 0; --i) {
            swap(p, q);
            p += q * vec[i];
        }
        trim();
    }

    vector<int> res() {
        
        vector<int> re;
        while (q != 0) {
            //cout << "cur " << p << ' ' << q << '\n';
            re.push_back(p / q);
            p %= q;
            swap(p, q);
        }
        return re;
    }
    
    void trim() {
        ll g = __gcd(p, q);
        p /= g, q /= g;
    }

};

Frac add(const Frac& a, const Frac& b) {
    return Frac(a.p * b.q + a.q * b.p, a.q * b.q);
}

Frac sub(const Frac& a, const Frac& b) {
    return Frac(a.p * b.q - a.q * b.p, a.q * b.q);
}

Frac mul(const Frac& a, const Frac& b) {
    return Frac(a.p * b.p, a.q * b.q);
}

Frac div(const Frac& a, const Frac& b) {
    return Frac(a.p * b.q, a.q * b.p);
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    vector<int> a, b;
    cin >> n >> m;
    For (i, n) {
        int d;
        cin >> d;
        a.push_back(d);
    }
    For (i, m) {
        int d;
        cin >> d;
        b.push_back(d);
    }

    Frac x(a), y(b);
    vector<int> ans[4] = {add(x, y).res(), sub(x, y).res(), mul(x, y).res(), div(x, y).res()};

    For (i, 4) {
        for (auto v : ans[i]) {
            cout << v << ' ';
        }
        cout << '\n';
    }

    return 0;
}

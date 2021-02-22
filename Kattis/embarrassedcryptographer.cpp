// https://open.kattis.com/problems/embarrassedcryptographer
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
const ll IINF = 1e18;
const double eps = 1e-12;

string s;
vector<ll> K;
int L;

bool np[1000010];
vector<int> primes;

ll reminder(int rem) {
    ll re = 0;
    For (i, K.size()) {
        re *= 1000000000;
        re += K[i];
        re %= rem;
    }
    return re;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    np[0] = np[1] = 1;
    for (int i = 2; i * i <= 1000000; i++) {
        if (!np[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                np[j] = 1;
            }
        }
    }
    for (int i = 2; i <= 1000000; i++) {
        if (!np[i]) primes.push_back(i);
    }

    string s;
    while (cin >> s >> L && L) {
        K.clear();
        int len = (s.length() + 8) / 9;

        int d = len * 9 - s.length();
        string sd;
        For (i, d)  sd.push_back('0');
        s = sd + s;

        For (i, len) {
            ll d = 0;
            For (j, 9) {
                int idx = 9 * i + j;
                d *= 10;
                d += s[idx] - '0';
            }
            K.push_back(d);
        }

        // For (i, K.size()) {
        //     cout << K[i] << ' ';
        // }
        // cout << '\n';

        bool flg = 0;
        int i = 0;
        while (i < primes.size() && primes[i] < L) {
            if (reminder(primes[i]) == 0) {
                cout << "BAD " << primes[i] << '\n';
                flg = 1;
                break;
            }
            i++;
        }
        if (!flg) {
            cout << "GOOD\n";
        }

    }

    return 0;
}

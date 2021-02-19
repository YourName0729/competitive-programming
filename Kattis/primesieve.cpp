// prime_factoring
// https://open.kattis.com/problems/primesieve
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

//vector<bool> prime;
//bitset<100000001> prime;
//int bs[3125010];

// void setter(int i, bool b) {
//     int idx = i >> 5, sft = i & 31;
//     if (b) {
//         bs[idx] |= (1 << sft);
//     }
//     else {
//         bs[idx] &= ((int)-1 ^ (1 << sft));
//     }
// }

// bool getter(int i) {
//     //int idx = , sft = ;
//     return bs[i >> 5] & (1 << (i & 31));
// }

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<bool> bs(n + 1);
    //prime.set();
    //prime.resize(n + 1, 1);
    //setter(0, 1);
    //setter(1, 1);
    bs[1] = 1;
    //prime[0] = prime[1] = 0;
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (!bs[i]) {
            ans++;
            if (i >= 10001) continue;
            for (int j = i * i; j <= n; j += i) {
                bs[j] = 1;
            }
        }

        /*if (prime[cur]) {
            //cout << "prime " << cur << '\n';
            ans++;
            for (int j = cur * cur; j <= n; j += cur) {
                prime[j] = 0;
            }
        }*/
    }

    cout << ans << '\n';
    int d;
    while (q--) {
        
        cin >> d;
        cout << !bs[d] << '\n';
        //cout << !getter(d) << '\n';
        //cout << prime[d] << '\n';
    }

    return 0;
}
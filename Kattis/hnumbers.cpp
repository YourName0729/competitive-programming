// number_theory
// https://open.kattis.com/problems/hnumbers
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
const double eps = 1e-12;

int n, m;
vector<bool> prime;
vector<int> prms;
int cnt[250010];

int mul(int a, int b) {
    return 4 * a * b + a + b;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    prime.resize(250001, 1);
    prime[0] = 0;
    for (int i = 1; 4 * i * i + 2 * i <= 250000; i++) {
        if (!prime[i])  continue;
        for (int j = 4 * i * i + 2 * i; j <= 250000; j += 4 * i + 1) {
            prime[j] = 0;
        }
    }
    for (int i = 1; i <= 250000; i++) {
        if (prime[i]) prms.push_back(i);
    }

    //cout << prms.size() << '\n';

    for (int i = 0; i < prms.size() && mul(prms[i], prms[i]) <= 250000; i++) {
        for (int j = i; j < prms.size() && mul(prms[i], prms[j]) <= 250000; j++) {
            //int d = 4 * mul(prms[i], prms[j]) + 1;
            //if (d < 100) cout << "semi: " << d << '\n';
            cnt[mul(prms[i], prms[j])] = 1;
        }
    }

    int sum = 0;
    for (int i = 0; i <= 250000; i++) {
        sum += cnt[i];
        cnt[i] = sum;
    }   

    int n;
    while (cin >> n && n) {
        cout << n << ' ' << cnt[(n - 1) / 4] << '\n';
    }

    return 0;
}
// prime_facctoring searching
// https://open.kattis.com/problems/zadaca
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9;//1e9 + 7;
const ll INF = 1e18;

int n, m;
ll a[1010], b[1010];
map<int, int> da, db;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n)  cin >> a[i];
    cin >> m;
    For (i, m)  cin >> b[i];

    For (i, n) {
        ll c = 2;
        while (a[i] != 1) {
            if (c * c > a[i]) {
                da[a[i]]++;
                break;
            }
            if (a[i] % c == 0) {
                da[c]++;
                a[i] /= c;
            }
            else {
                c++;
            }
        }
    }

    For (i, m) {
        ll c = 2;
        while (b[i] != 1) {
            if (c * c > b[i]) {
                db[b[i]]++;
                break;
            }
            if (b[i] % c == 0) {
                db[c]++;
                b[i] /= c;
            }
            else {
                    c++;
            }
        }
    }

    // for (auto p : da) {
    //     cout << p.first << ' ' << p.second << '\n';
    // }

    // for (auto p : db) {
    //     cout << p.first << ' ' << p.second << '\n';
    // }

    bool ex = 0;
    ll ans = 1;
    for (auto p : da) {
        if (db.count(p.first)) {
            For (i, min(p.second, db[p.first])) {
                ans = ans * p.first;
                if (ans >= MOD) {
                    ex = 1;
                }
                ans %= MOD;
            }
        }
    }

    if (ex)
        cout << setw(9) << setfill('0') << ans << '\n';
    else
        cout << ans << '\n';

    return 0;
}
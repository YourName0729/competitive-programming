// https://open.kattis.com/problems/logland
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

int n;
vector<ll> acc, arr;

ll _exp(ll b, ll m) {
    if (m == 0) return 1;
    ll t = _exp(b, m / 2);
    if (m % 2 == 0) return t * t % MOD;
    return t * t % MOD * b % MOD;
}

void show() {
    cout << "arr: ";
    for (auto v : arr) cout << v << ' ';
    cout << "\nacc: ";
    for (auto v : acc) cout << v << ' ';
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    For (i, n) {
        int x;
        cin >> x;
        arr.push_back(x);
        acc.push_back(x);
    }

    for (int i = 0; i < acc.size() - 1; ++i) {
        acc[i + 1] += acc[i] / 2;
        acc[i] %= 2;
    }
    // show();
    ll ans = 0;
    while (arr.size()) {
        ll k = arr.back() / 2;
        arr.back() -= 2 * k;
        acc.back() -= 2 * k;
        
        if (arr.back()) {
            if (acc.back() >= 2) {
                // find eq val from lower currency
                ll dem = 2;
                for (int i = arr.size() - 2; i >= 0; --i) {
                    if (arr[i] > dem) {
                        arr[i] -= dem;
                        break;
                    }
                    else {
                        dem -= arr[i];
                        dem *= 2;
                        arr[i] = 0;
                    }
                }
                --acc.back();
            }
            else {
                // discard
                ans = (ans + _exp(2, arr.size() - 1)) % MOD;
            }

            --acc.back();
        }
        
        if (acc.back()) acc[acc.size() - 2] += 2 * acc.back();

        // show();
        arr.pop_back();
        acc.pop_back();
    }

    cout << ans << '\n';

    return 0;
}
// https://open.kattis.com/problems/gigcombinatorics
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    ll a = 0, b = 0, ans = 0;
    int k;
    cin >> n;

    For (i, n) {
        cin >> k;
        switch (k) {
            case 1:
                a = (a + 1) % MOD;
                ++b;
                break;
            case 2:
                a = (2 * a) % MOD;
                break;
            case 3:
                ans = (ans + a - b + MOD) % MOD;
        }
    }

    cout << ans << '\n';
    
    

    return 0;
}
// https://open.kattis.com/problems/fruitbaskets
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
int arr[50];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    ll ans = 0;

    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int s = arr[i] + arr[j];
            if (s >= 200) ans += s;
        }
    }

    
    for (int i = 0; i < n; ++i) {
        int s = arr[i];
        if (s >= 200) ans += s;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int s = arr[i] + arr[j] + arr[k];
                if (s >= 200) ans += s;
            }
        }
    }

    if (n >= 4) {
        // 2^n - 1 - (n - 1) - (n - 1)*(n - 2) / 2 
        ll k = ((ll)1 << (n - 1)) - 1 - (n - 1) - (n - 1) * (n - 2) / 2;
        ll s = 0;
        for (int i = 0; i < n; ++i) s += arr[i];
        // cout << k << ' ' << s << '\n';
        ans += s * k;
    }

    cout << ans << '\n';

    return 0;
}
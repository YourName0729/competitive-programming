// https://open.kattis.com/problems/largesthoarding
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

    cin >> n;

    ll ans = 0;
    ll h, w, accw = 0;;
    vector<ar<ll, 2>> vec; // {height, leftmost}
    For (i, n) {
        cin >> h >> w;
        accw += w;
        ll l = accw - w;
        while (vec.size() && vec.back()[0] >= h) l = vec.back()[1], vec.pop_back();
        vec.push_back({h, l});
        // cout << i << '\n';
        for (auto [ah, al] : vec) {
            // cout << ah << ' ' << al << '\n';
            ans = max(ans, 50 * ah * (accw - al));
        }
    }

    cout << ans << '\n';

    return 0;
}
// https://open.kattis.com/problems/maximumfix
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
    unordered_map<int, int> mp;

    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x - 1 <= i){
            ++mp[i - x + 1];
            // cout << i - x + 1 << '\n';
        }
        else {
            ++mp[n - (x - i) + 1];
            // cout << n - (x - i) + 1 << '\n';
        } 
        // cout << x << ' ' << (x - i - 3 + n) % n << '\n';
    }

    int mxk, mxv = -1;
    for (auto& [k, v] : mp) {
        // cout << k << ' ' << v << '\n';
        if (v > mxv) {
            mxv = v;
            mxk = k;
        }
        else if (v == mxv) mxk = min(mxk, k);
    }

    cout << mxk << ' ' << mxv << '\n';

    return 0;
}
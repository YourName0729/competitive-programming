//
// https://open.kattis.com/problems/incognito
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
map<string, int> mp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    Forcase {
        mp.clear();
        cin >> n;
        For (i, n) {
            string s;
            cin >> s >> s;
            mp[s]++;
        }

        ll ans = 1;
        for (auto p : mp) {
            ans *= (p.second + 1);
        }
        cout << ans - 1 << '\n';
    }

    return 0;
}
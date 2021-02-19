//
// https://open.kattis.com/problems/longswaps
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;

int n, m;

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    string s, t;
    cin >> s;
    t = s;
    int k;
    cin >> k;

    if (k <= s.length() / 2) {
        cout << "Yes\n";
        return 0;
    }

    int l = s.length() - k, r = k - 1;
    //cout << l << ' ' << r << '\n';
    sort(s.begin(), s.end());
    //cout << s << '\n';
    for (int i = l; i <= r; i++) {
        if (s[i] != t[i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}
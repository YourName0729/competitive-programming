//
// https://open.kattis.com/problems/height
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

set<int> vec;

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;
        vec.clear();
        int ans = 0;
        For (i, 20) {
            int cur;
            cin >> cur;
            for (int e : vec) {
                if (e > cur)    ans++;
            }
            vec.insert(cur);
        }
        cout << d << ' ' << ans << '\n';
    }

    return 0;
}
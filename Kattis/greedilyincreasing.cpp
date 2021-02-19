//
// https://open.kattis.com/problems/greedilyincreasing
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define For1(i, n) for(int i = 1; i <= n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;

int n, k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    int prv = 0;
    vector<int> ans;
    For (i, n) {
        int d;
        cin >> d;
        if (d > prv) {
            ans.push_back(d);
            prv = d;
        }
        
    }

    cout << ans.size() << '\n';
    for (auto d : ans) {
        cout << d << ' ';
    }
    cout << '\n';

    return 0;
}
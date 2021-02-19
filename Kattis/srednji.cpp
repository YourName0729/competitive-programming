// greedy
// https://open.kattis.com/problems/srednji
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

int n, t;
int a[100010];
map<int, int> mp;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> t;
    For (i, n)  cin >> a[i];

    int at = 0;
    For (i, n)
        if (a[i] == t)
            at = i;

    int cnt = 0;
    for (int i = at; i < n; i++) {
        if (a[i] > t)   cnt++;
        if (a[i] < t)   cnt--;
        mp[cnt]++;
    }

    ll ans = 0;
    cnt = 0;
    for (int i = at; i >= 0; i--) {
        if (a[i] > t)   cnt--;
        if (a[i] < t)   cnt++;
        ans += mp[cnt];
    }


    cout << ans << '\n';

    return 0;
}
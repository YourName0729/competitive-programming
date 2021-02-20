// 
// https://open.kattis.com/problems/akcija
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

int n;
int arr[100010];

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    ll ans = 0;
    For (i, n) {
        cin >> arr[i];
        ans += arr[i];
    }

    sort(arr, arr + n);

    for (int i = n % 3; i < n; i += 3) {
        ans -= arr[i];
    }

    cout << ans << '\n';

    return 0;
}
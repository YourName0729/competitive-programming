// iteration
// https://open.kattis.com/problems/bungeebuilder
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
int arr[1000010];

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n) {
        cin >> arr[i];
    }

    if (n == 0) {
        cout << "0\n";
        return 0;
    }

    int ans = 0;
    int l = 0, r = 1;
    int mn = MOD;
    while (r < n) {
        mn = min(mn, arr[r]);
        ans = max(ans, min(arr[l], arr[r]) - mn);
        if (arr[r] >= arr[l]) {
            l = r;
            mn = arr[r];
        }
        r++;
    }

    cout << ans << '\n';

    return 0;
}
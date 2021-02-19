// greedy
// https://open.kattis.com/problems/mali
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
int arr[110], brr[110];
int ca[110], cb[110];

int solve(int m) {
    int mx = 0;
    int l = 1, r = 100;
    while (1) {
        while (l <= 100 && ca[l] == 0) l++;
        while (r >= 0 && cb[r] == 0) r--;
        if (l > 100 && r < 0) break;
        mx = max(mx, l + r);
        int mn = min(ca[l], cb[r]);
        ca[l] -= mn;
        cb[r] -= mn;
    }
    return mx;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n) {
        int a, b;
        cin >> a >> b;
        arr[a]++, brr[b]++;
        For (i, 101) {
            ca[i] = arr[i];
            cb[i] = brr[i];
        }

        cout << solve(i + 1) << '\n';
    }
    

    return 0;
}
 
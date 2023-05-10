// https://open.kattis.com/problems/shortsell
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

int n, k;
int arr[100010];
int ans = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;
    For (i, n) cin >> arr[i];

    int b = 0;
    For (i, n) {
        ans = max(ans, 100 * (arr[b] - arr[i]) - k * (i - b + 1));
        if (k * (i - b) >= 100 * (arr[b] - arr[i])) b = i;
    }
    cout << ans << '\n';

    return 0;
}
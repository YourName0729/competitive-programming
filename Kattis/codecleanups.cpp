// https://open.kattis.com/problems/codecleanups
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
int arr[1010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    if (arr[n - 1] == 365) --n;
    arr[n] = 1000;
    ++n;

    int ans = 0, sm = 0, w = 1;
    for (int i = 1; i < n; ++i) {
        sm += w * (arr[i] - arr[i - 1]);
        if (sm >= 20) {
            ++ans;
            sm = 0, w = 1;
        }
        else {
            ++w, sm = 0;
        }
    }
    cout << ans << '\n';

    return 0;
}
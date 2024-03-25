// https://open.kattis.com/problems/font
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
int arr[30] = {0};
int ans = 0;

void dfs(int k, int prv) {
    if (prv == (1 << 26) - 1) {
        ans += (1 << (n - k));
        return;
    }
    if (k == n) return;
    dfs(k + 1, prv);
    dfs(k + 1, prv | arr[k]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    For (i, n) {
        string s;
        cin >> s;
        for (auto c : s) arr[i] |= (1 << (c - 'a'));
    }

    dfs(0, 0);
    cout << ans << '\n';

    return 0;
}
// https://open.kattis.com/problems/cakeymccakeface
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

int n, m;
int arr[2010], brr[2010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    For (i, n) cin >> arr[i];
    For (i, m) cin >> brr[i];

    unordered_map<int, int> mp;
    For (i, n) {
        For (j, m) {
            if (arr[i] > brr[j]) continue;
            ++mp[brr[j] - arr[i]];
        }
    }

    int ansk = 0, ansv = 0;
    for (auto& [k, v] : mp)
        if (v > ansv || (v == ansv && k < ansk)) {
            ansk = k, ansv = v;
        }

    cout << ansk << '\n';

    return 0;
}
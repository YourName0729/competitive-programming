// https://open.kattis.com/problems/eko
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
ll m;
int arr[1000010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        r = max(r, arr[i]);
    }
    
    while (l < r) {
        int mid = (l + r + 1) / 2;
        ll s = 0;
        for (int i = 0; i < n; ++i) s += (arr[i] > mid)? arr[i] - mid : 0;

        // cout << mid 

        if (s < m) r = mid - 1;
        else l = mid;
    }

    cout << l << '\n';

    return 0;
}
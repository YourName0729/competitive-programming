// https://open.kattis.com/problems/disgruntledjudge
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
ll arr[10010];

bool ok(ll a, ll b) {
    For (i, n - 1) {
        if (arr[i + 1] != (a * a * arr[i] + a * b + b) % 10001) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    For (i, n) cin >> arr[i];

    For (a, 10001) For (b, 10001) {
        if (ok(a, b)) {
            For (i, n) {
                cout << (arr[i] * a + b) % 10001 << '\n';
            }
            return 0;
        }
    }

    return 0;
}
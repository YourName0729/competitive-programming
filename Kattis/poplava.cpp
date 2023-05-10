// https://open.kattis.com/problems/poplava
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

ll n;
ll x;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> x;
    if (x > (n - 2) * (n - 1) / 2) {
        cout << "-1\n";
        return 0;
    }

    vector<int> unuse;
    cout << n << ' ';
    for (int i = 1; i <= n - 2; ++i) {
        if (x >= n - 1 - i) {
            cout << i << ' ';
            x -= n - 1 - i;
        }
        else unuse.push_back(i);
    }

    cout << n - 1 << ' ';
    for (auto it = unuse.rbegin(); it != unuse.rend(); ++it) cout << *it << ' ';
    cout << '\n';

    return 0;
}
// https://open.kattis.com/problems/contestadvancement
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

int n, k, c;
int cnt[100010] = {0};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k >> c;
    vector<array<int, 2>> ans, pot;
    for (int i = 0, t, s; i < n; ++i) {
        cin >> t >> s;
        if (k == 0) continue;
        if (cnt[s] < c) {
            ans.push_back({i, t});
            ++cnt[s];
            --k;
            
        }
        else {
            pot.push_back({i, t});
        }
    }

    for (int i = 0; i < k; ++i) ans.push_back(pot[i]);

    sort(ans.begin(), ans.end());
    for (auto [p, q] : ans) cout << q << '\n';

    return 0;
}
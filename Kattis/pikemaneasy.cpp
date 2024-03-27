// https://open.kattis.com/problems/pikemaneasy
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
ll t, a, b, c, t0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> t;
    cin >> a >> b >> c >> t0;

    vector<int> vec;
    vec.push_back(t0);
    for (int i = 0; i < n - 1; ++i) {
        vec.push_back((a * vec.back() + b) % c + 1);
    }
    sort(vec.begin(), vec.end());

    int ans = 0;
    ll sm = 0, penalty = 0;
    for (int i = 0; i < vec.size(); ++i) {
        if (sm + vec[i] <= t) {
            ++ans;
            sm += vec[i];
            penalty = (penalty + sm) % MOD;
        }
        else break;
    }
    cout << ans << ' ' << penalty << '\n';

    return 0;
}
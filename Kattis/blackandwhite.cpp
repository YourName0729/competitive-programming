// https://open.kattis.com/problems/blackandwhite
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
double pos[30], neg[30];
double dp[2000010];

double f(int u) {
    if (dp[u] != -1) return dp[u];

    double sp = 0.0, sn = 0.0;
    for (int i = 0; i < n; ++i) {
        if (u & (1 << i)) sp += pos[i], sn += neg[i];
    }

    double p_tie = 1.0;
    double re = 1;

    for (int i = 0; i < n; ++i) {
        if (u & (1 << i)) {
            // cout << sp << ' ' << pos[i] << ' ' << neg[i] << '\n';
            double p_out = exp(sp - pos[i] + neg[i]) + exp(sn - neg[i] + pos[i]);
            re += p_out * f(u ^ (1 << i));
            p_tie -= p_out;
            //cout << p_out << ' ' << p_tie << '\n';
        }
    }

    re /= 1 - p_tie;

    // cout << bitset<5>(u) << " is " << re << '\n';

    return dp[u] = re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    double x;
    For (i, n) {
        cin >> x;
        pos[i] = log(x);
        neg[i] = log(1 - x);
    }

    fill(dp, dp + (1 << n), -1);

    For (i, n) {
        for (int j = i + 1; j < n; ++j) {
            dp[(1 << i) | (1 << j)] = 0;
        }
    }

    cout << fixed << setprecision(12) << f((1 << n) - 1) << '\n';
 
    return 0;
}
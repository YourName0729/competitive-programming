//
// https://open.kattis.com/problems/posterize
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int n, k;
long long r[266], p[266];
long long w[266][266];
long long dp[266][266];
long long s[266];
long long v[266];

long long cal(int bot, int top, long long mid) {
    long long re = 0;
    for (int i = bot; i <= top; i++) {
        re += p[i] * (r[i] - mid) * (r[i] - mid);
    }
    return re;
}

void build() {
    long long sum = 0;
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum += p[i];
        s[i] = sum;
    }

    long long val = 0;
    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        val += r[i] * p[i];
        v[i] = val;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            long long mid = (v[j] - v[i - 1]) / (s[j] - s[i - 1]);
            w[i][j] = min(cal(i, j, mid), cal(i, j, mid + 1));
        }
    }
}

long long f(int nn, int kk) {
    if (kk >= nn)   return 0;
    if (dp[nn][kk] != 0)    return dp[nn][kk]; 
    if (kk == 1) {
        dp[nn][kk] = w[1][nn];
        return dp[nn][kk];
    }

    long long ans = f(nn - 1, kk - 1);
    for (int i = 2; i < nn; i++) {
        ans = min(ans, f(nn - i, kk - 1) + w[nn - i + 1][nn]);
    }

    dp[nn][kk] = ans;
    return ans;
}

int main() {
    fast;

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> r[i] >> p[i];
    }
    
    build();
    cout << f(n, k) << '\n';

    return 0;
}
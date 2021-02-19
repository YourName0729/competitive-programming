// dp
// https://open.kattis.com/problems/cudak
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define forcase int __t;cin >> __t;while (__t--)
#define For(i, n) for(int i = 0; i < n; i++)

using ll = long long;

using namespace std;

ll dp[15][136];

ll count(ll A, ll S) {
    if (A == 0) return dp[0][S];
    
    vector<int> dgt;
    while (A) {
        dgt.push_back(A % 10);
        A /= 10;
    }

    int pfx = 0;
    ll sum = 0;
    for (int free = dgt.size(); free > 0; free--) {
        for (int num = 0; num < dgt[free - 1]; num++) {
            if (S - num - pfx >= 0)
                sum += dp[free - 1][S - num - pfx];
        }
        pfx += dgt[free - 1];
    }
    if (pfx == S)   sum++;

    return sum;
}

ll first(ll A, ll B, ll S) {
    ll l = A, r = B;
    while (l != r) {
        ll mid = (l + r) / 2;
        if (count(mid, S) - count(A - 1, S) >= 1) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    fast;

    dp[0][0] = 1;
    for (int d = 1; d < 15; d++) {
        for (int s = 0; s <= 135; s++) {
            for (int i = 0; i <= 9; i++) {
                if (s - i >= 0) {
                    dp[d][s] += dp[d - 1][s - i];
                }
            }
        }
    }
    

    ll A, B, S;
    cin >> A >> B >> S;

    cout << count(B, S) - count(A - 1, S) << '\n';
    cout << first(A, B, S) << '\n';
    
    return 0;
}

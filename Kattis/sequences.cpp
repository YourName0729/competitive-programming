// dp
// https://open.kattis.com/problems/sequences
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define INF 2000000000

#define MOD 1000000007

using ll = long long;

using namespace std;

string s;
int n1, nq;
ll p[500010];
ll dp[500010];

int main() {
    fast;

    
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    n1 = (s[0] == '1');
    nq = (s[0] == '?');
    p[0] = 1;
    dp[0] = 0;
    for (int i = 1; i < s.length(); i++) {
        p[i] = (2 * p[i - 1]) % MOD;
    }

    for (int cur = 1; cur < s.length(); cur++) {
        if (s[cur] == '0') {
            dp[cur] = dp[cur - 1];
        } else {
            ll sum = 0;
            if (nq == 0) {
                sum = cur - n1;
            } else {
                sum = (((cur - n1) * p[nq]) % MOD + MOD - (nq * p[nq - 1]) % MOD) % MOD;
            }

            if (s[cur] == '1') {
                dp[cur] = (dp[cur - 1] + sum) % MOD;
                n1++;
            } else {
                dp[cur] = (2 * dp[cur - 1] + sum) % MOD;
                nq++;
            }
        }
    }

    cout << dp[s.length() - 1] << '\n';
 
    return 0;
}

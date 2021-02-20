// 
// https://open.kattis.com/problems/permutationdescent
#include <iostream>
//#include <deque>
//#include <algorithm>
//#include <cmath>
//#include <vector>
//#include <set>

using namespace std;

long long M = 1001113;
long long dp[110][110];

long long f(long long n, long long m) {
    if (m == 0 || n - m == 1)   return 1;
    if (dp[n][m] != 0)  return dp[n][m];
    
    return dp[n][m] = ((m + 1) * f(n - 1, m) % M + (n - m) * f(n - 1, m - 1) % M) % M;  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    int t, cnt, n, m;
    cin >> t;
    while (t--) {
        cin >> cnt >> n >> m;
        cout << cnt << ' ' << f(n, m) << '\n';
    }
    
    return 0;
} 
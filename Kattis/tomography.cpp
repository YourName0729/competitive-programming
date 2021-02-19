// greedy
// https://open.kattis.com/problems/tomography
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

int n, m;
int X[1010], Y[1010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    For (i, n)  cin >> X[i];
    For (i, m)  cin >> Y[i];

    For (i, n) {
        sort(Y, Y + m);
        for (int j = 0; j < X[i]; j++) {
            int at = m - 1 - j;
            if (Y[at] == 0) {
                cout << "NO\n";
                return 0;
            }
            Y[at]--;
        }
    }

    For (i, m) {
        if (Y[i] != 0) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    
    return 0;
}
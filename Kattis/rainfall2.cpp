// simulation
// https://open.kattis.com/problems/rainfall2
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;

double L, K, T1, T2, H;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> L >> K >> T1 >> T2 >> H;

    double B = (T1 + T2) * K + H;
    double D = B * B - 4 * T1 * L * K;
    //cout << (B + sqrt(D)) / 2;
    double ans = (B + sqrt(D)) / 2;
    if (H < L) {
        cout << fixed << H << ' ' << H << '\n';
    }
    else {
        if (abs(H - L) < 0.001) {
            cout << fixed << H << ' ' << ans << '\n'; 
        }
        else {
            cout << fixed << ans << ' ' << ans << '\n';
        }
    }

    return 0;
}
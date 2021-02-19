//
// https://open.kattis.com/problems/teacherevaluation
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



int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);

    int n, p, s = 0;

    cin >> n >> p;
    For (i, n) {
        int d;
        cin >> d;
        s += d;
    }

    if (p == 100) {
        cout << "impossible\n";
        return 0;
    }

    for (int k = 1; ; k++) {
        int mx = s + 100 * k;
        if (mx >= p * (n + k)) {
            cout << k << '\n';
            return 0;
        }
    }

    return 0;
}
//
// https://open.kattis.com/problems/vauvau
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

int a, b, c, d;

bool atk(int x, int y, int t) {
    return t % (x + y) <= x && 1 <= t % (x + y);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> a >> b >> c >> d;
    For (i, 3) {
        int t;
        cin >> t;
        if (atk(a, b, t) && atk(c, d, t)) {
            cout << "both\n";
        }
        else if (atk(a, b, t) || atk(c, d, t)) {
            cout << "one\n";
        }
        else {
            cout << "none\n";
        }
    }
    

    return 0;
}
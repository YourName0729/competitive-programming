// case_considering
// https://open.kattis.com/problems/squaredeal
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9;//1e9 + 7;
const ll INF = 1e18;

int h[3], w[3];


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    For (i, 3)  cin >> h[i] >> w[i];

    if (h[0] == h[1] && h[1] == h[2]) {
        if (w[0] + w[1] + w[2] == h[0]) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
    }
    else if (h[1] == h[2] && h[1] == h[0] - w[0] && w[1] + w[2] == h[0]) {
        cout << "YES";
    }
    else if (h[1] == w[2] && h[1] == h[0] - w[0] && w[1] + h[2] == h[0]) {
        cout << "YES";
    }
    else if (w[1] == h[2] && w[1] == h[0] - w[0] && h[1] + w[2] == h[0]) {
        cout << "YES";
    }
    else if (w[1] == w[2] && w[1] == h[0] - w[0] && w[1] + h[2] == h[0]) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}
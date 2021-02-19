//
// https://open.kattis.com/problems/santaklas
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


    int h, v;
    cin >> h >> v;
    if (v >= 0 && v <= 180) {
        cout << "safe\n";
        return 0;
    }

    double pi = acos(-1);

    v -= 180;
    if (v >= 90)    v = 180 - v;
    double ans = h / sin(v / 360.0 * 2 * pi);
    cout << (int)floor(ans) << '\n';


    return 0;
}
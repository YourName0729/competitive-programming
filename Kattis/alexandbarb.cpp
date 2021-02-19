// game
// https://open.kattis.com/problems/alexandbarb
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
    ios_base::sync_with_stdio(false); cin.tie(0);

    int k, m, n;
    cin >> k >> m >> n;
    k %= (m + n);
    if (k < m) {
        cout << "Barb\n";
    }
    else {
        cout << "Alex\n";
    }


    return 0;
}
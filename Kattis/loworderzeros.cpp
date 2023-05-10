// https://open.kattis.com/problems/loworderzeros
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

int c5(int n) {
    int k = 5;
    int re = 0;
    while (k <= n) {
        re += n / k;
        k *= 5;
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    while (cin >> n && n) {
        int c = c5(n);

        int ans = 1;
        for (int i = 2; i <= n; ++i) {
            int k = i;
            while (k % 5 == 0) k /= 5;
            while (c && k % 2 == 0) k /= 2, --c;
            ans = (ans * k) % 10;
        }
        cout << ans << '\n';
    }

    return 0;
}
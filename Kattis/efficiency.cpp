// https://open.kattis.com/problems/efficiency
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

int p, m;
string s[] = {"Efficiency", "Unbreaking", "Silk", "Touch"};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    auto update = [&](int& cur, int& turn, int idx) {
        if (turn == m) {
            cout << s[idx] << '\n';
        }
        cur = (cur + 1) % p;
        ++turn;
    };

    cin >> p >> m;
    int cur = 0, turn = 1;
    for (int rnd = 1;; ++rnd) {
        For (i, rnd) update(cur, turn, 0);
        For (i, rnd) update(cur, turn, 1);
        For (i, rnd) {
            update(cur, turn, 2);
            update(cur, turn, 3);
        }
        if (turn > m) {
            cout << (cur - 1 + p) % p + 1 << '\n';
            return 0;
        }
    }

    return 0;
}
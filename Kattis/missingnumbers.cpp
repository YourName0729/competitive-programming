//
// https://open.kattis.com/problems/missingnumbers
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ar array

using namespace std;

const int MOD = 1e9 + 7;

int n;
int a[210];
bool vst[210];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    For (i, n) {
        cin >> a[i];
        vst[a[i]] = true;
    }

    bool flg = false;
    for (int i = 1; i < a[n - 1]; i++) {
        if (!vst[i]) {
            flg = true;
            cout << i << '\n';
        }
    }

    if (!flg) {
        cout << "good job\n";
    }
    

    return 0;
}

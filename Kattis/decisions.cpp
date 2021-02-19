// divided_and_conquer
// https://open.kattis.com/problems/decisions
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

int n;
ll pn;
int arr[300000];
int inc[300000];

ll need(int l, int r) {
    //cout << l << ' ' << r << '\n';
    if (l + 1 == r) return 1;
    int mid = (l + r) / 2;
    if (inc[l] == inc[r - 1]) {
        //cout << l << ' ' << r << " same\n";
        return 1;
    }    
    //ll ans = 1 + need(l, mid) + need(mid + 1, r);
    //cout << l << ' ' << r << ": " << ans << '\n';
    return 1 + need(l, mid) + need(mid, r);
}

ll pow2(ll d) {
    if (d == 0) return 1;
    ll re = pow2(d / 2);
    if (d % 2 == 0) {
        return re * re;
    }
    else {
        return re * re * 2;
    }
}

int rev(int d, int n) {
    int re = 0;
    For (i, n) {
        re <<= 1;
        re += d % 2;
        d >>= 1;
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    pn = pow2(n);
    For (i, pow2(n)) {
        //cout << "rev of " << i << " = " << rev(i, n) << '\n';
        cin >> arr[rev(i, n)];
    }

    int c = 0;
    inc[0] = 0;
    int i = 0;
    while (i < pn) {
        int j = i;
        while (j + 1 < pn && arr[j + 1] == arr[j]) {
            j++;
        }
        for (int k = i; k <= j; k++) {
            inc[k] = c;
        }
        c++;
        i = j + 1;
    }

    // For (i, pow2(n)) {
    //     cout << arr[i] << ' ';
    // }
    // cout << '\n';
    // For (i, pow2(n)) {
    //     cout << inc[i] << ' ';
    // }
    // cout << '\n';

    cout << need(0, pn) << '\n';

    return 0;
}
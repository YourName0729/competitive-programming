// divide_and_conquer
// https://open.kattis.com/problems/outofsorts
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define Show(a,n) For(i,n) cout << a[i] << ' ';cout << '\n';
#define ll long long
#define ar array

using namespace std;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

int n;
ll m, a, c;
ll arr[1000010], brr[1000010];

int bs(int bot, int top, ll mn, ll mx) {
    if (top < bot)  return 0;
    //cout << bot << ' ' << top << ' ' << mn << ' ' << mx << '\n';

    int mid = (bot + top) / 2;
    int re = bs(bot, mid - 1, mn, min(mx, arr[mid])) + bs(mid + 1, top, max(mn, arr[mid]), mx);
    if (mn < arr[mid] && arr[mid] < mx) {
        re++;
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> a >> c >> arr[0];
    for (int i = 1; i <= n; i++) {
        arr[i] = brr[i] = (a * arr[i - 1] % m + c) % m;
    }

    sort(brr + 1, brr + n + 1);

    /*for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= n; i++) {
        cout << brr[i] << ' ';
    }
    cout << '\n';*/

    cout << bs(1, n, -1, m) << '\n';

    return 0;
}
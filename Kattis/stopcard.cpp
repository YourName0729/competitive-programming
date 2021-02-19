// probability
// https://open.kattis.com/problems/stopcard
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

int n, c;
int a[100];


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> c;
    for (int i = 1; i <= n; i++)  cin >> a[i];
    sort(a + 1, a + n + 1);

    if (c == 0) {
        double s = 0;
        for (int i = 1; i <= n; i++) s += a[i];
        cout << fixed << s / (double)n;
        return 0;
    }

    double ans = 0, w = 1, s = 0;
    for (int i = c; i <= n - 1; i++) {
        w = c;
        for (int j = 1; j <= i - 1; j++)    w *= j;
        for (int j = 1; j <= i - c; j++)    w /= j;
        for (int j = 1; j <= n - c; j++)    w *= j;
        for (int j = 1; j <= n; j++)        w /= j;
        s = 0;
        for (int j = i + 1; j <= n; j++)    s += a[j];
        ans += w * s / (double)(n - i);
        //cout << w << ' ' << s << '\n';
    }
    s = 0;
    for (int i = 1; i <= n - 1; i++)  s += a[i];
    ans += c / (double)n / (double)(n - 1) * s;

    cout << ans << '\n';


    return 0;
}
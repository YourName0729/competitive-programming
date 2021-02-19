// sorting_and_searching
// https://open.kattis.com/problems/firefly
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;

int n, h;
int a[200010], b[200010];

int hit(int d) {
    int re = 0;
    int l = 0, r = n / 2 - 1;
    if (d <= a[n / 2 - 1]) {
        while (l < r) {
            int mid = (l + r) / 2;
            if (d <= a[mid]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        re += n / 2 - l;
    }
    
    if (h - d + 1 <= b[n / 2 - 1]) {
        l = 0, r = n / 2 - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (h - d + 1 <= b[mid]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        re += n / 2 - l;        
    }

    return re;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> h;
    For (i, n) {
        if (i % 2 == 0) cin >> a[i / 2];
        else    cin >> b[i / 2];
    }

    sort(a, a + (n / 2));
    sort(b, b + (n / 2));

    int m = n, w = 0;
    for (int i = 1; i <= h; i++) {
        int d = hit(i);
        //out << i << ' ' << d << "!\n";
        if (d < m) {
            m = d;
            w = 1;
        }
        else if (d == m)    w++;
    }

    cout << m << ' ' << w;

    return 0;
}
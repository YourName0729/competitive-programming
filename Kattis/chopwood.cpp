// Prufer_code tree
// https://open.kattis.com/problems/chopwood
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

int n;
int a[200010];
bool vst[200010];
int ans[200010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n)  cin >> a[i];
    if (a[n - 1] != n + 1) {
        cout << "Error";
        return 0;
    }

    int b = n;
    for (int i = n - 1; i >= 0; i--) {
        if (i != 0 && a[i - 1] != n + 1 && !vst[a[i - 1]]) {
            ans[i] = a[i - 1];
            vst[a[i - 1]] = 1;
        }
        else {
            while (vst[b]) {
                b--;
            }
            vst[b] = 1;
            ans[i] = b;
        }
    }

    For (i, n) {
        cout << ans[i] << '\n';
    }

    return 0;
}
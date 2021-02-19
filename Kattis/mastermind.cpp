//
// https://open.kattis.com/problems/mastermind
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define For1(i, n) for(int i = 1; i <= n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;

int n;
char a[100], b[100];
bool vsta[100], vstb[100];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n) {
        cin >> a[i];
    }
    For (i, n) {
        cin >> b[i];
    }

    int r = 0, s = 0;
    For (i, n) {
        if (a[i] == b[i]) {
            vsta[i] = vstb[i] = 1;
            r++;
        }
    }

    For (i, n) {
        if (!vstb[i]) {
            For (j, n) {
                if (!vsta[j] && a[j] == b[i]) {
                    vsta[j] = vstb[i] = 1;
                    s++;
                    break;
                }
            }
        }
    }

    cout << r << ' ' << s << '\n';

    return 0;
}
// group_theory 
// https://open.kattis.com/problems/bread
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
int a[100010], b[100010], av[100010];
bool vst[100010];

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        av[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vst[i]) {
            int l = 0;
            int at = i;
            while (!vst[at]) {
                vst[at] = 1;
                l++;
                at = av[b[at]];
            }
            cnt += l - 1;
        }
        
    }

    cout << (cnt % 2 == 0? "Possible" : "Impossible");

    return 0;
}
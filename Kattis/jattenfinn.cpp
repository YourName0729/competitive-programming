// dynamic_programming dp
// https://open.kattis.com/problems/jattenfinn
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;

int n;
ll arr[100010];
int prv[100010];
int nxt[100010];
bool op[100010];

int smul(int cur) {
    op[cur] = 1;
    int l = cur - 1, r = cur + 1;
    while (1) {
        int w = (r - l + 1) * 500;
        bool flg = 0;

        if (arr[l] < w) {
            flg = 1;
            if (op[l]) l = prv[l];
            else l--;
        }
        if (arr[r] < w) {
            flg = 1;
            r++;
        }
    
        if (!flg)   break;
    }
    prv[cur] = l;
    nxt[cur] = r;
    return r - l - 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    arr[0] = arr[n + 1] = INF;

    int mx = smul(1), idx = 1;
    for (int i = nxt[1]; i <= n; i = nxt[i]) {
        int d = smul(i);
        if (d > mx) {
            mx = d;
            idx = i;
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << prv[i] << ' ' << nxt[i] << '\n';
    // }

    cout << mx << ' ' << idx - 1 << '\n';


    return 0;
} 


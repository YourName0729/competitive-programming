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

bool vst[200010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(vst, 0, n + 1);
        int ans = 0;
        For (i, n) {
            int v;
            cin >> v;
            ans += vst[v];
            vst[v] = 1;
        }
        cout << ans << '\n';
    }
    


    return 0;
}
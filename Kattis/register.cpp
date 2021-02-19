//
// https://open.kattis.com/problems/register
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

int of[8] = {2, 3, 5, 7, 11, 13, 17, 19};
int cur[8];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int cnt = 1, ans = 0;
    For (i, 8) {
        cin >> cur[i];
        ans += cnt * (of[i] - cur[i] - 1);
        cnt *= of[i];
    }   
    

    cout << ans << '\n';

    return 0;
}
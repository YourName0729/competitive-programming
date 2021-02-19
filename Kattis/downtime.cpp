// greedy
// https://open.kattis.com/problems/downtime
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

int n, k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    queue<int> que;

    cin >> n >> k;
    int mx = 0;
    For (i, n) {
        int t;
        cin >> t;
        que.push(t);
        while (que.front() <= t - 1000)  que.pop();
        mx = max(mx, (int)que.size());
    }

    //cout << "mx " << mx << '\n';

    if (mx % k == 0) {
        cout << mx / k << '\n';
    }
    else {
        cout << mx / k + 1 << '\n';
    }

    return 0;
}
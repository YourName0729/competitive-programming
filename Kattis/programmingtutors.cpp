// bipartite_matching binary_searching
// https://open.kattis.com/problems/programmingtutors
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

int n;
int xa[110], ya[110], xb[110], yb[110];
int match[110];
bool vst[110];

int dist(int i, int j) {
    return abs(xa[i] - xb[j]) + abs(ya[i] - yb[j]);
}

bool dfs(int u, int d) {
    For (i, n) {
        if (dist(u, i) <= d && !vst[i]) {
            vst[i] = 1;
            if (match[i] == -1 || dfs(match[i], d)) {
                match[i] = u;
                return 1;
            }
        }
    }
    return 0;
}

bool ok(int d) {
    For (i, n) {
        match[i] = -1;
    }

    int re = 0;
    For (i, n) {
        For (i, n) {
            vst[i] = 0;
        }

        if (dfs(i, d)) re++;
    }
    return re == n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    For (i, n)  cin >> xa[i] >> ya[i];
    For (i, n)  cin >> xb[i] >> yb[i];

    int l = 0, r = 4 * 1e8;
    while (l < r) {
        int mid = (l + r) / 2;
        if (ok(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << l << '\n';

    return 0;
}
//
// https://open.kattis.com/problems/safe
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

int tb[3][3];
int dp[300000];

void fetch(int d) {
    for (int i = 2; i >= 0; i--) {
        for (int j = 2; j >= 0; j--) {
            tb[i][j] = d % 4;
            d /= 4;
        }
    }
}

int store() {
    int re = 0;
    For (i, 3) {
        For (j, 3) {
            re *= 4;
            re += tb[i][j];
        }
    }
    return re;
}

void add(int x, int y) {
    For (i, 3) {
        For (j, 3) {
            if (i == x || j == y) {
                tb[i][j]--;
                if (tb[i][j] < 0) tb[i][j] += 4;
            }
        }
    }
}

void bfs() {
    queue<int> que;
    dp[0] = 0;
    que.push(0);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        For (i, 3) {
            For (j, 3) {
                fetch(cur);
                add(i, j);
                if (dp[store()] == -1) {
                    dp[store()] = dp[cur] + 1;
                    que.push(store());
                }
            }
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);

    For (i, 300000) {
        dp[i] = -1;
    }

    bfs();
    
    For (i, 3) {
        For (j, 3) {
            cin >> tb[i][j];
        }
    }

    cout << dp[store()] << '\n';

    return 0;
}
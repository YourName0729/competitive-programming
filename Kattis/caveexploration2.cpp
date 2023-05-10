// https://open.kattis.com/problems/caveexploration2
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

int n;
int arr[110][110];
bool vst[110][110];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool ok(int th) {
    For (i, n) For (j, n) vst[i][j] = 0;

    queue<ar<int, 2>> que;
    que.push({0, 0});
    vst[0][0] = 1;
    while (que.size()) {
        auto [x, y] = que.front();
        que.pop();
        

        For (i, 4) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vst[nx][ny] || arr[nx][ny] > th) continue;
            que.push({nx, ny});
            vst[nx][ny] = 1;
        }
    }
    return vst[n - 1][n - 1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    For (i, n) For (j, n) cin >> arr[i][j];

    int l = 0, r = 1e8 + 1;
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
// graph_traversal tree cycle DAG
// https://open.kattis.com/problems/dugovi
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; i++)
#define FOR1(i, n) for (int i = 1; i <= n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9 + 7;
const int INF = 2147483647;

int n;
int A[200010];
int B[200010];
int E[200010];
int dg[200010];
int prv[200010];
bool vst[200010];

int dfs(int i) {
    vst[i] = 1;
    int cur = A[i];
    int mx = B[i] - E[i];
    while (cur != i) {
        vst[cur] = 1;
        mx = min(mx, B[cur] - E[cur]);
        cur = A[cur];
    }
    return mx;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    For (i, n) {
        cin >> A[i] >> B[i], A[i]--;
        dg[A[i]]++;
    }

    queue<int> que;

    For (i, n) {
        if (dg[i] == 0) que.push(i);
    }

    int ans = 0;
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        if (vst[cur]) continue;
        vst[cur] = 1;
        if (E[cur] < B[cur]) {
            ans += B[cur] - E[cur];
        }

        dg[A[cur]]--;
        E[A[cur]] += B[cur];
        if (dg[A[cur]] == 0 || E[A[cur]] >= B[A[cur]]) {
            que.push(A[cur]);
        }
    }

    //cout << ans << '\n';

    For (i, n) {
        if (!vst[i]) {
            prv[A[i]] = i;
        }
    }

    //cout << ans << '\n';

    For (i, n) {
        if (!vst[i] && B[i] - E[i] - B[prv[i]] > 0) {
            ans += B[i] - E[i] - B[prv[i]];
            E[i] = B[i] - B[prv[i]];
        }
    }

    //cout << ans << '\n';

    For (i, n) {
        if (!vst[i]) {
            ans += dfs(i);
        }
    }

    cout << ans << '\n';

    return 0;
}

// dp
// https://open.kattis.com/problems/spiderman
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-9;

int n;
int a[50];
bool dp[50][1010];
bool drct[50][1010];

bool f(int i, int d, int H) {
    if (d < 0 || d > H)  return 0;
    return dp[i][d];
}

bool ok(int H) {
    For (i, H + 1)   dp[0][i] = 0;
    dp[0][a[0]] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= H; j++) {
            dp[i][j] = f(i - 1, j - a[i], H) || f(i - 1, j + a[i], H);
            drct[i][j] = f(i - 1, j - a[i], H);
        }
    }
    return dp[n - 1][0];
}

int bs() {
    if (!ok(1000))  return -1;
    int l = 0, r = 1000;
    while (l < r) {
        int mid = (l + r) / 2;
        if (ok(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        cin >> n;
        For (i, n)  cin >> a[i];

        int ans = bs();

        if (ans == -1) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            ok(ans);
            vector<char> ans;
            int d = 0;
            for (int i = n - 1; i >= 1; i--) {
                if (drct[i][d]) {
                    d -= a[i];
                    ans.push_back('U');
                }
                else {
                    d += a[i];
                    ans.push_back('D');
                }
            }
            cout << 'U';
            for (int i = ans.size() - 1; i >= 0; i--) {
                cout << ans[i];
            }
            cout << '\n';
        }
    }

    return 0;
}
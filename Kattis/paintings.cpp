// dicision_tree
// https://open.kattis.com/problems/paintings
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

int n, m;
bool adj[20][20];
map<string, int> s2i;
string i2s[20];

bool flg;
int tmp[20];
int ansarr[20];

int f(int state, int prv, int step) {
    if (state == 0) {
        //if (!flg)
            For (i, n) {
                ansarr[i] = tmp[i];
            }
        //flg = true;
        return 1;
    }
    int re = 0;
    For (i, n) {
        if ((state & (1 << i)) && adj[i][prv]) {
            tmp[step] = i;
            re += f(state ^ (1 << i), i, step + 1);
        }
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    Forcase {
        cin >> n;
        s2i.clear();
        flg = false;
        For (i, n) {
            For (j, n) {
                if (i != j) adj[i][j] = 1;
            }
        }
        For (i, n) {
            cin >> i2s[n - i - 1];
            s2i[i2s[n - i - 1]] = n - i - 1;
        }

        cin >> m;
        For (i, m) {
            string a, b;
            cin >> a >> b;

            adj[s2i[a]][s2i[b]] = adj[s2i[b]][s2i[a]] = 0;
        }

        int ans = 0;
        For (i, n) {
            tmp[0] = i;
            ans += f((1 << n) - 1 - (1 << i), i, 1);
        }

        cout << ans << '\n';
        For (i, n) {
            cout << i2s[ansarr[i]] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
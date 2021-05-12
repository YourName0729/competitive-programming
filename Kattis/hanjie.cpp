// https://open.kattis.com/problems/hanjie
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ar array

using namespace std;
using namespace __gnu_pbds;

template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-12;

int n, m;
vector<int> an[10], bn[10];
bool bd[10][10];
int ans = 0;

vector<int> form(int x, int y, int px, int py) {
    vector<int> org;
    int pfx = 0;
    while (x < n && y < m) {
        if (!bd[x][y] && pfx != 0) {
            org.push_back(pfx);
            pfx = 0;
        }
        else if (bd[x][y]) {
            pfx++;
        }
        x += px, y += py;
    }
    if (pfx != 0) org.push_back(pfx);
    return org;
}

bool exact(int x, int y, int px, int py, vector<int>& cmp) {
    vector<int> org = form(x, y, px, py);
    if (org.size() != cmp.size())   return 0;
    For (i, org.size()) {
        if (org[i] != cmp[i])   return 0;
    }
    return 1;
}

bool legal(int x, int y, int px, int py, vector<int>& cmp) {
    vector<int> org = form(x, y, px, py);
    if (org.size() == 0)    return 1;
    if (org.size() > cmp.size())    return 0;
    For (i, org.size() - 1) {
        if (org[i] != cmp[i])   return 0;
    }
    return org.back() <= cmp[org.size() - 1];
}

bool ok(int x, int y) {
    if (!legal(x, 0, 0, 1, an[x]) || !legal(0, y, 1, 0, bn[y])) return 0;
    if (x == n - 1 && !exact(0, y, 1, 0, bn[y]))    return 0;
    if (y == m - 1 && !exact(x, 0, 0, 1, an[x]))    return 0;
    return 1;

}

void dfs(int x, int y) {
    //cout << x << ' ' << y << '\n';
    if (x == n) {
        // cout << "!!!\n";
        // For (i, n) {
        //     For (j, m) {
        //         cout << bd[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        ans++;
        return;
    }

    int nx = x, ny = y + 1;
    if (ny == m) nx++, ny = 0;

    //cout << "cur: " << x << ' ' << y << '\n';

    if (ok(x, y)) {
        //cout << x << ' ' << y << "ass: 0\n";
        dfs(nx, ny);
    }
    // else {
    //     cout << x << ' ' << y << " not ass 0\n";
    // }
    bd[x][y] = 1;
    if (ok(x, y)) {
        //cout << x << ' ' << y << " ass: 1\n";
        dfs(nx, ny);
    }
    // else {
    //     cout << x << ' ' << y << " not ass 1\n";
    // }
    bd[x][y] = 0;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    string s;
    For (i, n) {
        int k, d;
        cin >> k;
        For (j, k) {
            cin >> d;
            an[i].push_back(d);
        }
    }
    For (i, m) {
        int k, d;
        cin >> k;
        For (j, k) {
            cin >> d;
            bn[i].push_back(d);
        }
    }

    dfs(0, 0);

    cout << ans << '\n';

    return 0;
}

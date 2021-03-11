// https://open.kattis.com/problems/chainco
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
using namespace __gnu_pbds;
 
template<class Type> using indexed_set=tree<Type,null_type,less<Type>,rb_tree_tag,tree_order_statistics_node_update>;
 
const int MOD = 1e9 + 7;
const int INF = 2147483647;
const ll IINF = 1e18;
const double eps = 1e-12;

int t, n;
vector<ar<int, 6>> x, y, z;

bool run() {
    int inside[4], outside[4];
    int xmin, xmax;
    for (int i = 0; i < 2; ++i) {
        inside[2] = inside[3] = outside[0] = outside[1] = 2e9;
        inside[0] = inside[1] = outside[2] = outside[3] = -2e9;
        xmin = 2e9;
        xmax = -2e9;
    }
    for (int i = 0; i < x.size(); ++i) {
        int y1 = x[i][1], y2 = x[i][4], z1 = x[i][2], z2 = x[i][5];
        if (y1 > y2) swap(y1, y2);
        if (z1 > z2) swap(z1, z2);
        outside[0] = min(outside[0], y1);
        outside[1] = min(outside[1], z1);
        outside[2] = max(outside[2], y2);
        outside[3] = max(outside[3], z2);
        inside[0] = max(inside[0], y1);
        inside[1] = max(inside[1], z1);
        inside[2] = min(inside[2], y2);
        inside[3] = min(inside[3], z2);
        xmin = min(xmin, x[i][0]);
        xmax = max(xmax, x[i][0]);
    }
    for (int i = 0; i < y.size(); ++i) {
        int x1 = y[i][0], x2 = y[i][3];
        int z1 = y[i][2], z2 = y[i][5];
        if (x1 > x2) swap(x1, x2);
        if (z1 > z2) swap(z1, z2);
        if (x1 < xmin && xmax < x2 &&
            inside[0] < y[i][1] && y[i][1] < inside[2] &&
            ((z1 < outside[1] && inside[1] < z2 && z2 < inside[3]) || 
            (inside[1] < z1 && z1 < inside[3] && outside[3] < z2))) continue;
        return false;
    }
    for (int i = 0; i < z.size(); ++i) {
        int x1 = z[i][0], x2 = z[i][3];
        int y1 = z[i][1], y2 = z[i][4];
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        if (x1 < xmin && xmax < x2 &&
            inside[1] < z[i][2] && z[i][2] < inside[3] &&
            ((y1 < outside[0] && inside[0] < y2 && y2 < inside[2]) || 
            (inside[0] < y1 && y1 < inside[2] && outside[2] < y2))) continue;
        return false;
    }
    return true;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        array<int, 6> plain;
        x.clear();
        y.clear();
        z.clear();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 6; ++j) cin >> plain[j];
            if (plain[0] == plain[3]) x.push_back(plain);
            else if (plain[1] == plain[4]) y.push_back(plain);
            else z.push_back(plain);
        }

        if ((x.empty() && y.empty()) ||
            (y.empty() && z.empty()) ||
            (x.empty() && z.empty())) {
                cout << "NO\n";
                continue;
            }
        
        if (!x.empty() && run()) {
            cout << "YES\n";
            continue;
        }
        for (int i = 0; i < x.size(); ++i) {
            swap(x[i][0], x[i][1]);
            swap(x[i][3], x[i][4]);
        }
        for (int i = 0; i < y.size(); ++i) {
            swap(y[i][0], y[i][1]);
            swap(y[i][3], y[i][4]);
        }
        for (int i = 0; i < z.size(); ++i) {
            swap(z[i][0], z[i][1]);
            swap(z[i][3], z[i][4]);
        }
        swap(x,y);
        if (!x.empty() && run()) {
            cout << "YES\n";
            continue;
        }
        for (int i = 0; i < x.size(); ++i) {
            swap(x[i][0], x[i][2]);
            swap(x[i][3], x[i][5]);
        }
        for (int i = 0; i < y.size(); ++i) {
            swap(y[i][0], y[i][2]);
            swap(y[i][3], y[i][5]);
        }
        for (int i = 0; i < z.size(); ++i) {
            swap(z[i][0], z[i][2]);
            swap(z[i][3], z[i][5]);
        }
        swap(x,z);
        if (!x.empty() && run()) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }

    return 0;
}

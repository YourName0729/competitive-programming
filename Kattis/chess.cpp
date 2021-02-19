//
// https://open.kattis.com/problems/chess
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

set<pair<int, int>> st1, st2;

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};

void make(int x, int y, set<pair<int, int>>& st) {
    For (i, 4) {
        int nx = x, ny = y;
        while (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8) {
            st.insert({nx, ny});
            nx += dx[i];
            ny += dy[i];
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        st1.clear();
        st2.clear();
        int x1, y1, x2, y2;
        char c1, c2;
        cin >> c1 >> y1 >> c2 >> y2;
        x1 = c1 - 'A' + 1, x2 = c2 - 'A' + 1;
        if ((abs(x1 - x2) + abs(y1 - y2)) % 2 == 1) {
            cout << "Impossible\n";
        }
        else if (x1 == x2 && y1 == y2) {
            cout << 0 << ' ' << c1 << ' ' << y1 << '\n';
        }
        else {
            make(x1, y1, st1);
            make(x2, y2, st2);
            if (st1.count({x2, y2}) || st2.count({x1, y1})) {
                cout << "1 " << c1 << ' ' << y1 << ' ' << c2 << ' ' << y2 << '\n';
            }
            else {
                auto i1 = st1.begin();
                auto i2 = st2.begin();
                while (i1 != st1.end() && i2 != st2.end()) {
                    if (*i1 < *i2) {
                        ++i1;
                    }
                    else if (*i1 > *i2) {
                        ++i2;
                    }
                    else {
                        cout << 2 << ' ' << c1 << ' ' << y1 << ' ' << (char)(i1->first + 'A' - 1) << ' ' << i1->second << ' ' << c2 << ' ' << y2 << '\n';
                        break;
                    }
                }
            }
        }
    }


    return 0;
}
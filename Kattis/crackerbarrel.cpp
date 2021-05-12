// https://open.kattis.com/problems/crackerbarrel
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

int dx[] = {0, 1, 0, -1, 1, -1};
int dy[] = {1, 0, -1, 0, -1, 1};

set<ll> st;

int tmp[5][5];

char pick;

ll encode() {
   ll re = 0;
   For (i, 5) {
       for (int j = 0; j < 5 - i; j++) {
           re *= 3;
           re += tmp[i][j];
       }
   } 
   return re;
}

void decode(ll d) {
    for (int i = 4; i >= 0; i--) {
        for (int j = 4 - i; j >= 0; j--) {
            tmp[i][j] = d % 3;
            d /= 3;
        }
    }
}

bool end() {
    int cnt = 0;
    int is;
    For (i, 5) {
        for (int j = 0; j < 5 - i; j++) {
            if (tmp[i][j] != 0) {
                cnt++;
                if (cnt > 1) return 0;
                is = tmp[i][j];
            }
        }
    }
    return cnt == 1 && is == 1;
}

bool gg() {
    For (i, 5) {
        for (int j = 0; j < 5 - i; j++) {
            if (tmp[i][j] == 1)  return 0;
        }
    }
    return 1;
}

void show() {
    For (i, 5) {
        for (int j = 0; j < 5 - i; j++) {
            cout << tmp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool bfs(ll s) {
    queue<ll> que;
    que.push(s);
    st.insert(s);
    decode(s);
    if (end()) {
        return 1;
    }
    if (gg()) {
        return 0;
    }
    while (que.size()) {
        ll u = que.front();
        que.pop();

        decode(u);

        if (end()) {
            return 1;
        }

        For (i, 5) {
            for (int j = 0; j < 5 - i; j++) {
                if (!tmp[i][j]) continue;
                For (k, 6) {
                    int nx = i + dx[k], ny = j + dy[k];
                    int nnx = nx + dx[k], nny = ny + dy[k];
                    if (nnx < 0 || nny < 0 || nnx + nny >= 5)   continue;
                    if (tmp[nx][ny] == 0 || tmp[nnx][nny] != 0) continue;
                    int a = tmp[i][j], b = tmp[nx][ny], c = tmp[nnx][nny];
                    tmp[i][j] = tmp[nx][ny] = 0, tmp[nnx][nny] = a;
                    ll v = encode();
                    if (!st.count(v) && !gg()) {
                        st.insert(v);
                        que.push(v);
                    }
                    tmp[i][j] = a, tmp[nx][ny] = b, tmp[nnx][nny] = c;
                }
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    char c;
    while (cin >> c >> c && c != '*') {
        pick = c;
        st.clear();
        For (i, 5) {
            int x = i, y = 0;
            For (j, i + 1) {
                cin >> c >> c;
                tmp[x][y] = (c == '_'? 0 : (c == pick? 1 : 2));
                --x, ++y;
            }
        }


        if (bfs(encode())) {
            cout << "Possible\n";
        }
        else {
            cout << "Impossible\n";
        }

    }
    
    return 0;
}

// https://open.kattis.com/problems/bananaproblem
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

struct D {
    bool ladder = 0;
    int idx = 0, idx2 = 0, h = 0, x = 0, y = 0;
    int len = 0;
};

struct E {
    bool ladder = 0;
    ll len = 0, h = 0;
    ll x = 0, y = 0;
};

int N, H, R, B;
vector<D> vec;
ar<int, 2> monkey[300010];
vector<E> event[300010];
int belong[300010];

bool cmp(D& a, D& b) {
    return a.h > b.h;
}

int solve(int idx) {
    //cout << idx << "-th monkey\n";
    ar<ll, 2> mon = {monkey[idx][0], monkey[idx][1]};
    ll time = 0;
    int prvh = 0;
    int ans = 0;
    for (int i = event[belong[idx]].size() - 1; i >= 0; i--) {
        E cur = event[belong[idx]][i];
        if (cur.ladder) {
            time += mon[0] * (cur.h - prvh);
            time += mon[1] * cur.len;
            prvh = cur.h;
            //cout << "arrive ladder h=" << cur.h << ", t=" << time << '\n';
        }
        else {
            int curh = cur.h;
            time += mon[0] * (curh - prvh);
            int t = time % (cur.x + cur.y);
            //cout << "arrive banana h=" << cur.h << ", t=" << time << ", x=" << cur.x << ", y=" << cur.y << '\n';
            if (t >= 1 && t <= cur.x) {
                ans++;
                //cout << "eat!\n";
            }
            prvh = curh;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> H >> R >> B;
    for (int i = 1; i <= R; i++) {
        D cur;
        cin >> cur.len >> cur.idx >> cur.idx2 >> cur.h;
        cur.ladder = 1;
        vec.push_back(cur);
    }
    for (int i = 1; i <= N; i++) {
        cin >> monkey[i][0] >> monkey[i][1];
    }
    for (int i = 1; i <= B; i++) {
        D cur;
        cin >> cur.idx >> cur.h >> cur.x >> cur.y;
        vec.push_back(cur);
    }

    sort(vec.begin(), vec.end(), cmp);

    for (int i = 1; i <= N; i++) belong[i] = i;

    For (i, vec.size()) {
        D cur = vec[i];
        if (cur.ladder) {
            int u = cur.idx, v = cur.idx2, h = cur.h, l = cur.len;
            swap(belong[u], belong[v]);
            E eve;
            eve.ladder = 1;
            eve.h = h;
            eve.len = l;
            event[belong[u]].push_back(eve);
            event[belong[v]].push_back(eve);
        }
        else {
            int idx = cur.idx, x = cur.x, y = cur.y, h = cur.h;
            int be = belong[idx];
            E eve;
            eve.x = x, eve.y = y;
            eve.h = h;
            event[be].push_back(eve);
        }
    }

    // for (int i = 1; i <= N; i++) {
    //     cout << i << "-th monley\n";
    //     for (int j = event[i].size() - 1; j >= 0; j--) {
    //         E cur = event[i][j];
    //         if (cur.ladder) {
    //             cout << "go ladder h=" << cur.h << ", l=" << cur.len << '\n';
    //         }
    //         else {
    //             cout << "banana h=" << cur.h << ", x=" << cur.x << ", y=" << cur.y << '\n';
    //         }
    //     }
    // }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += solve(i);
    }
    cout << ans;

    return 0;
}

// https://open.kattis.com/problems/inspectingillumination
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
const unsigned ll IINF = 1e18;
const double eps = 1e-12;

int n;
int ans[1010];
struct D {
    int l, r;
    vector<int> vec;
};
deque<D> que;

set<int> req(vector<int>& vec) {
    cout << "ASK " << vec.size() << ' ';
    for (auto v : vec) cout << v << ' ';
    cout << endl;
    set<int> re;
    For (i, vec.size()) {
        int d;
        cin >> d;
        re.insert(d);
    }
    return re;
}


int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    if (n == 1) {
        cout << "ANSWER 1" << endl;
        return 0;
    }

    vector<int> vec;
    For (i, n) vec.push_back(i + 1);
    que.push_back({1, n, vec});
    while (que.size()) {
        vector<int> all;
        int k = que.size();
        For (i, k) {
            D& cur = que[i];
            int mid = (cur.l + cur.r) / 2;
            for (int i = cur.l; i <= mid; ++i) all.push_back(i);
        }
        set<int> res = req(all);
        For (i, k) {
            D& cur = que[i];
            int mid = (cur.l + cur.r) / 2;
            vector<int> lvec, rvec;
            for (auto v : cur.vec) {
                if (res.count(v)) lvec.push_back(v);
                else rvec.push_back(v);
            }
            if (lvec.size() == 1) {
                ans[lvec.back()] = cur.l;
            }
            else {
                que.push_back({cur.l, mid, lvec});
            }
            if (rvec.size() == 1) {
                ans[rvec.back()] = cur.r;
            }
            else {
                que.push_back({mid + 1, cur.r, rvec});
            }
        }
        For (i, k) que.pop_front();
    }


    cout << "ANSWER ";
    For (i, n) {
        cout << ans[i + 1] << ' ';
    }
    cout << endl;
    
    return 0;
}

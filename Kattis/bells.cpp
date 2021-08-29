// https://open.kattis.com/problems/bells
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

vector<vector<int>> f(vector<vector<int>>& vec, int d) {
    vector<vector<int>> re;
    For (i, vec.size()) {
        if (i % 2 == 1) {
            For (j, vec.front().size()) {
                vector<int> cur;
                For (k, vec.front().size()) {
                    if (j == k) {
                        cur.push_back(d);
                    }
                    cur.push_back(vec[i][k]);
                }    
                re.push_back(cur);
            }    
            vec[i].push_back(d);
            re.push_back(vec[i]);
            vec[i].pop_back();
        }
        else {
            vec[i].push_back(d);
            re.push_back(vec[i]);
            vec[i].pop_back();
            for (int j = vec.front().size() - 1; j >= 0; --j) {
                vector<int> cur;
                For (k, vec.front().size()) {
                    if (j == k) {
                        cur.push_back(d);
                    }
                    cur.push_back(vec[i][k]);
                }    
                re.push_back(cur);
            } 
        }
    }
    return re;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> vec = {{1}};
    For (i, n - 1) {
        vec = f(vec, i + 2);
    }
    for (auto& v : vec) {
        for (auto vv : v) {
            cout << vv << ' ';
        }
        cout << '\n';
    }

    return 0;
}

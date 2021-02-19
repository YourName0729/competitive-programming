// sorting_and_searching
// https://open.kattis.com/problems/moviecollection
// inspired by mpfeifer1: https://github.com/mpfeifer1/Kattis/blob/master/moviecollection.cpp
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
const ll INF = 1e18;

int n, q;

struct cmp {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
        return a.second < b.second;
    }
};

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    Forcase {
        cin >> n >> q;

        set<pair<int, int>, cmp> st;
        indexed_set<pair<int, int>> ist;

        For (i, n) {
            st.insert({i, i + 1});
            ist.insert({i, i + 1});
        }

        For (i, q) {
            int x;
            cin >> x;
            
            auto p = *st.find({0, x});
            cout << ist.order_of_key(p) << ' ';

            st.erase(p);
            ist.erase(p);

            p.first = -i - 1;

            st.insert(p);
            ist.insert(p);
        }

        cout << '\n';
    }

    return 0;
}
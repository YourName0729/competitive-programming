// https://open.kattis.com/problems/targetpractice
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

int n;
ar<ll, 2> a[100010];

ar<ll, 2> operator-(ar<ll, 2> x, ar<ll, 2> y) {
    return {x[0] - y[0], x[1] - y[1]};
}
ll operator^(ar<ll, 2> x, ar<ll, 2> y) {
    return x[0] * y[1] - x[1] * y[0];
}

bool line(vector<int>& vec) {
    if (vec.size() <= 2)    return 1;
    ar<ll, 2> v = a[vec[0]] - a[vec[1]];
    for (int i = 2; i < vec.size(); i++) {
        if (((a[vec[i]] - a[vec[0]]) ^ v) != 0)    return 0;
    }
    return 1;
}

bool ok1() {
    ar<ll, 2> v = a[0] - a[1];
    vector<int> oth;
    for (int i = 2; i < n; i++) {
        if (((a[i] - a[0]) ^ v) != 0)   oth.push_back(i);
    }
    return line(oth);
}

bool ok2() {
    vector<int> oth;
    oth.push_back(1);
    ar<ll, 2> v = a[0] - a[2];
    for (int i = 3; i < n; i++) {
        if (((a[i] - a[0]) ^ v) != 0)   oth.push_back(i);
    }
    return line(oth);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    if (n <= 3) {
        cout << "success";;
        return 0;
    }
    For (i, n)  cin >> a[i][0] >> a[i][1];

    if (ok1()) {
        cout << "success";
        return 0;
    }
    if (ok2()) {
        cout << "success";
        return 0;
    }
    swap(a[0], a[1]);
    if (ok2()) {
        cout << "success";
        return 0;
    }

    cout << "failure\n";


    return 0;
}

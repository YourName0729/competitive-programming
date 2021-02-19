// bit_operation brute_force
// https://open.kattis.com/problems/base2palindrome
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

vector<unsigned int> vec;

unsigned int rev(unsigned int x) {
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
    
    return((x >> 16) | (x << 16));
}

void show(unsigned int d) {
    stack<char> stk;
    while (d) {
        stk.push((d & 1) + '0');
        d >>= 1;
    }
    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
}

void pal(unsigned int d, int i, bool mid) {
    unsigned r = rev(d) >> (32 - i);
    // cout << d << ':';
    // show(d);
    // cout << ", r:";
    // show(r);
    // cout << '\n';
    unsigned top = (1 << i) | r;
    unsigned int bot = (d << 1) | 1;
    if (mid) {
        unsigned f = (top << (i + 2)) | bot;
        vec.push_back(f);
        f |= (1 << (i + 1));
        vec.push_back(f);
    }
    else {
        vec.push_back((top << (i + 1)) | bot);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    For (i, 16) {
        For (j, (1 << i)) {
            pal(j, i, 0);
            if (i != 15)    pal(j, i, 1);
        }
    }
    vec.push_back(1);
    sort(vec.begin(), vec.end());
    //cout << vec.size() << '\n';
    int n;
    cin >> n;
    cout << vec[n - 1] << '\n';

    // For (i, 10) {
    //     show(vec[i]);
    //     cout << '\n';
    // }

    return 0;
}
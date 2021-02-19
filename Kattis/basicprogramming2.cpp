//
// https://open.kattis.com/problems/basicprogramming2
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

int n, t;
int a[200010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> t;
    For (i, n)  cin >> a[i];
    sort(a, a + n);
    if (t == 1) {
        int l = 0, r = n - 1;
        while (l < r) {
            if (a[l] + a[r] == 7777) {
                cout << "Yes";
                return 0;
            }
            else if (a[l] + a[r] > 7777) {
                r--;
            }
            else {
                l++;
            }
        }
        cout << "No";
    }
    else if (t == 2) {
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1]) {
                cout << "Contains duplicate";
                return 0;
            }
        }
        cout << "Unique";
    }
    else if (t == 3) {
        map<int, int> mp;
        For (i, n)  mp[a[i]]++;
        for (auto p : mp) 
            if (p.second > n / 2) {
                cout << p.first;
                return 0;
            }
        cout << "-1";
    }
    else if (t == 4) {
        if (n % 2 == 0) {
            cout << a[n / 2 - 1] << ' ' << a[n / 2];
        }
        else {
            cout << a[n / 2];
        }
    }
    else {
        For (i, n) {
            if (100 <= a[i] && a[i] <= 999) {
                cout << a[i] << ' ';
            }
        }
    }

    

    return 0;
}
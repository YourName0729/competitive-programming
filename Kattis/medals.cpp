// case_considering simplifying
// https://open.kattis.com/problems/medals
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

int n, N;
ar<int, 3> arr[30];
string name[30];

int point(int i, int w1, int w2, int w3) {
    return arr[i][0] * w1 + arr[i][1] * w2 + arr[i][2] * w3;
}

bool f(int e1, int e2, int e3) {
    int w1 = 1, w2 = 1, w3 = 1;
    For (i, e1) w1 *= N;
    For (i, e2) w2 *= N;
    For (i, e3) w3 *= N;

    for (int i = 1; i < n; i++) {
        if (point(i, w1, w2, w3) > point(0, w1, w2, w3))    return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n && n != 0) {
        int cnt = 1;
        For (i, n) {
            string s;
            cin >> s;
            if (s == "Canada") {
                For (j, 3)  cin >> arr[0][j];
            }
            else {
                name[cnt] = s;
                For (j, 3)  cin >> arr[cnt][j];

                bool flg = 0;
                for (int j = 1; j < cnt; j++) {
                    if (s == name[j])   flg = 1;
                }
                if (!flg) {
                    cnt++;
                }
            }
        }

        n = cnt;

        N = 0;
        For (i, n)  For (j, 3)  N += arr[i][j];

        if (f(0, 0, 0) || f(0, 0, 1) || f(0, 1, 0) || f(1, 0, 0) || f(0, 1, 1) || f(1, 0, 1) || f(1, 1, 0) || f(0, 1, 2) || f(0, 2, 1) || f(1, 0, 2) || f(1, 2, 0) || f(2, 0, 1) || f(2, 1, 0)) {
            cout << "Canada wins!\n";
        } 
        else {
            cout << "Canada cannot win.\n";
        }
    }
    
    return 0;
}
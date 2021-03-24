// https://open.kattis.com/problems/cardhands
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

struct D {
    int v = 0;
    D* ch[52] = {NULL};
};

int n;
D* rt = new D;
int ans;

void del(D* cur) {
    For (i, 52) {
        if (cur->ch[i] != NULL) {
            del(cur->ch[i]);
        }
    }
    delete cur;
}

char suit[] = {'C', 'D', 'H', 'S'};

int c2d(string s) {
    int re = 0;
    For (i, 4) {
        if (s.back() == suit[i]) {
            re += i * 13;
        }
    }
    if ('A' <= s.front() && s.front() <= 'Z') {
        if (s.front() == 'J') {
            re += 10;
        } 
        else if (s.front() == 'Q') {
            re += 11;
        }
        else if (s.front() == 'K') {
            re += 12;
        }
    }
    else {
        int d = s.front() - '0';
        if (d == 1) d = 10;
        re += d - 1;
    }
    return re;
}

void ins(D* cur, int i, vector<int>& vec) {
    if (i == vec.size()) {
        cur->v++;
        return;
    }
    int tar = vec[i];
    if (cur->ch[tar] == NULL) {
        ans++;
        cur->ch[tar] = new D;
    }
    ins(cur->ch[tar], i + 1, vec);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n && n) {
        del(rt);
        rt = new D;
        ans = 0;

        For (i, n) {
            vector<int> vec;
            int s;
            cin >> s;
            For (j, s) {
                string str;
                cin >> str;
                vec.push_back(c2d(str));
            }

            reverse(vec.begin(), vec.end());
            ins(rt, 0, vec);
        }

        cout << ans << '\n';
    }


    return 0;
}

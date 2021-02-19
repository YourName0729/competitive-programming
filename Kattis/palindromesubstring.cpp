// string_processing trie
// https://open.kattis.com/problems/palindromesubstring
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
    int v = 0;
    D* ch[26] = {NULL};
};
D* root;

void insert(D* cur, string& str, int idx, int end) {
    if (idx == end) {
        cur->v++;
        return;
    }
    int i = str[idx] - 'a';
    if (cur->ch[i] == NULL) {
        cur->ch[i] = new D;
    }
    insert(cur->ch[i], str, idx + 1, end);
}

void del(D* cur, int d) {
    For (i, 26) if (cur->ch[i]) del(cur->ch[i], d + 1);
    delete cur;
}

string pfx;
void show(D* cur) {
    if (cur->v) {
        cout << pfx << '\n';
    }
    For (i, 26) {
        if (cur->ch[i]) {
            pfx.push_back(i + 'a');
            show(cur->ch[i]);
            pfx.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    while (cin >> s) {
        root = new D;

        For (i, s.length()) {
            int d = 1;
            while (i - d >= 0 && i + d < s.length()) {
                if (s[i - d] == s[i + d]) {
                    insert(root, s, i - d, i + d + 1);
                    d++;
                }
                else break;
            }
        }
        For (i, s.length()) {
            int d = 0;
            while (i - d >= 0 && i + d + 1 < s.length()) {
                if (s[i - d] == s[i + d + 1]) {
                    insert(root, s, i - d, i + d + 2);
                    d++;
                }
                else break;
            }
        }

        show(root);
        cout << '\n';
        del(root, 0);
    }

    
    
    return 0;
}
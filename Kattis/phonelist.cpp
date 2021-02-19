// trie
// https://open.kattis.com/problems/phonelist
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define forcase int __t;cin>>__t;for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

struct Node {
    bool tail = false;
    Node* n[10] = {NULL};
};

string s;
int n;
Node* root = NULL;

bool add(Node* cur, int at) {
    if (at == s.length()) {
        cur->tail = true;
        bool ok = true;
        For (i, 10) {
            if (cur->n[i] != NULL) {
                ok = false;
            }
        }
        return ok;
    }  
    if (cur->tail)  return false;

    if (cur->n[s[at] - '0'] == NULL) {
        cur->n[s[at] - '0'] = new Node;
    }
    return add(cur->n[s[at] - '0'], at + 1);
}

void del(Node* cur) {
    if (cur == NULL)    return;

    For (i, 10) {
        if (cur->n[i] != NULL)
            del(cur->n[i]);
    }
    delete cur;
}

int main() {
    fast;

    forcase {
        cin >> n;

        root = new Node;

        bool ok = true;
        For (i, n) {
            cin >> s;
            if (ok && !add(root, 0)) {
                ok = false;
            }
        }

        cout << (ok? "YES\n" : "NO\n");
    }

    return 0;
}
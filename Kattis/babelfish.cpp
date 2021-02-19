//
// https://open.kattis.com/problems/babelfish
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>
#include <deque>

#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;
using namespace std;
const ll INF = 1000000010;
const ll MOD = 1000000007;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct Node {
    string s;
    Node* ch[26];
};

Node* root;

void add(Node* cur, int at, string& key, string& val) {
    if (at == key.length()) {
        cur->s = val;
        return;
    }

    if (cur->ch[key[at] - 'a'] == NULL) {
        cur->ch[key[at] - 'a'] = new Node;
    }

    add(cur->ch[key[at] - 'a'], at + 1, key, val);
}

string query(Node* cur, int at, string& key) {
    if (cur == NULL)    return "";
    if (at == key.length()) return cur->s;

    return query(cur->ch[key[at] - 'a'], at + 1, key);
}

int main() {
    //fast();

    root = new Node;

    string s, a, b;
    while (getline(cin, s) && s != "") {
        stringstream ss;
        ss << s;
        ss >> a >> b;

        add(root, 0, b, a);
    }
    while (cin >> s) {
        string ans = query(root, 0, s);
        if (ans != "") {
            cout << ans << '\n';
        } else {
            cout << "eh\n";
        }
    }

    return 0;
}
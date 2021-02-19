// simulation
// https://open.kattis.com/problems/setstack
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;

vector<vector<int>> mp;
stack<int> stk;
int n;

int idx(vector<int>& v) {
    For (i, mp.size()) {
        if (v == mp[i]) {
            return i;
        }
    }
    mp.push_back(v);
    return mp.size() - 1;
}

int unn(int a, int b) {
    vector<int> v;
    int i = 0, j = 0;
    int sa = mp[a].size(), sb = mp[b].size();
    while (i < sa && j < sb) {
        if (mp[a][i] < mp[b][j]) {
            v.push_back(mp[a][i]);
            i++;
        }
        else if (mp[a][i] > mp[b][j]) {
            v.push_back(mp[b][j]);
            j++;
        }
        else {
            v.push_back(mp[b][j]);
            i++, j++;
        }
    }

    while (i < sa) {
        v.push_back(mp[a][i]);
        i++;
    }
    while (j < sb) {
        v.push_back(mp[b][j]);
        j++;
    }

    return idx(v);
}

int its(int a, int b) {
    vector<int> v;
    int i = 0, j = 0;
    int sa = mp[a].size(), sb = mp[b].size();
    while (i < sa && j < sb) {
        if (mp[a][i] < mp[b][j]) {
            i++;
        }
        else if (mp[a][i] > mp[b][j]) {
            j++;
        }
        else {
            v.push_back(mp[b][j]);
            i++, j++;
        }
    }

    return idx(v);
}

int add(int a, int b) {
    swap(a, b);
    vector<int> v;
    int i = mp[a].size() - 1;
    while (i >= 0 && mp[a][i] > b)    i--;
    if (i == -1) {
        v.push_back(b);
        For (j, mp[a].size()) {
            v.push_back(mp[a][j]);
        }
    }
    else if (mp[a][i] != b) {
        For (j, i + 1) {
            v.push_back(mp[a][j]);
        }
        v.push_back(b);
        for (int j = i + 1; j < mp[a].size(); j++) {
            v.push_back(mp[a][j]);
        }
    }
    else {
        return idx(mp[a]);
    }
    return idx(v);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    Forcase {
        mp.clear();
        while (!stk.empty())    stk.pop();
        mp.push_back(vector<int>());

        cin >> n;
        while (n--) {
            string s;
            cin >> s;
            if (s == "PUSH") {
                stk.push(0);
            }
            else if (s == "DUP") {
                stk.push(stk.top());
            }
            else if (s == "UNION") {
                int v1 = stk.top();
                stk.pop();
                int v2 = stk.top();
                stk.pop();
                stk.push(unn(v1, v2));
            }
            else if (s == "INTERSECT") {
                int v1 = stk.top();
                stk.pop();
                int v2 = stk.top();
                stk.pop();
                stk.push(its(v1, v2));
            }
            else if (s == "ADD") {
                int v1 = stk.top();
                stk.pop();
                int v2 = stk.top();
                stk.pop();
                stk.push(add(v1, v2));
            }
            cout << mp[stk.top()].size() << '\n';
        }
        cout << "***\n";
    }


    return 0;
} 

// binary_tree
// https://open.kattis.com/problems/succession
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <utility>
#include <queue>
#include <iomanip>
#include <deque>
#include <set>

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9
#define EPS 1e-9

using ull = unsigned long long;
using ll = long long;
using namespace std;

struct Peo {
    double val = -1;
    string name;
    Peo *fa = NULL, *fb = NULL;
};

int n, m;
string fth;
Peo arr[200];
int sz = 0;
map<string, int> mp;

double f(Peo* cur) {
    if (cur->val != -1) return cur->val;
    if (cur->fa == NULL)   return 0;
    cur->val = (f(cur->fa) + f(cur->fb)) / 2;
    return cur->val;
}

int newP(string name) {
    int at = sz++;
    arr[at].name = name;
    mp[name] = at;
    return at;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin >> n >> m;
    cin >> fth;
    newP(fth);
    arr[0].val = 1;

    For (i, n) {
        string name, fan, fbn;
        cin >> name >> fan >> fbn;

        int at;
        if (mp.count(name)) {
            at = mp[name];
        } else {
            at = newP(name);
        }

        int ata, atb;
        if (!mp.count(fan)) {
            ata = newP(fan);
        } else {
            ata = mp[fan];
        }
        if (!mp.count(fbn)) {
            atb = newP(fbn);
        } else {
            atb = mp[fbn];
        }

        arr[at].fa = &arr[ata];
        arr[at].fb = &arr[atb];
    }

    // For (i, sz) {
    //     cout << arr[i].name << ' ';
    // }
    // cout << '\n';

    int ans = -1;
    For (i, m) {
        string clm;
        cin >> clm;
        
        int at;
        if (mp.count(clm)) {
            at = mp[clm];
        } else {
            continue;
        }
        if (ans == -1 || f(&arr[ans]) < f(&arr[at])) {
            ans = at;
        }
    }
    
    cout << arr[ans].name << '\n';

    return 0;
}
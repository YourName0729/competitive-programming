//
// https://open.kattis.com/problems/grandpabernie
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>
#include <map>

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

using ull = unsigned long long;
using ll = long long;
using namespace std;

int n;
map<string, vector<int>> mp;

int main() {

    cin >> n;
    For (i, n) {
        string s;
        int y;
        cin >> s >> y;
        mp[s].push_back(y);
    }

    // Fore (p, mp) {
    //     sort(p.second.begin(), p.second.end());
    // }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }

    int q;
    cin >> q;
    For (i, q) {
        string s;
        int k;
        cin >> s >> k;
        cout << mp[s][k - 1] << '\n';
    }

    return 0;
}
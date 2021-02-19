//
// https://open.kattis.com/problems/summertrip
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define ll long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9 + 7;

string s;

ll ms(int bot, int top) {
    if (top < bot)  return 0;
    if (bot == top) return 0;
    if (bot + 1 == top) return (s[bot] != s[top]);

    ll re = 0;
    map<char, int> mp;
    vector<int> num(26, 0);
    vector<bool> vst(26, false);

    int mid = (bot + top) / 2;

    //cout << "calc " << bot << ' ' << mid << ' ' << top << '\n';
    
    for (int i = mid + 1; i <= top; i++) {
        if (!mp.count(s[i])) {
            mp[s[i]] = i;
        }
    }

    // for (auto p : mp) {
    //     cout << p.first << ' ' << p.second << "\n";
    // }

    /*For (i, 26) {
        if (!mp.count('a' + i)) {
            num[i] = mp.size();
        }
        else {
            int d = 0;
            for (auto p : mp) {
                if (p.second < mp['a' + i]) {
                    d++;
                }
            }
            num[i] = d;
        }
    }*/

    for (int i = mid; i >= bot; i--) {
        if (!vst[s[i] - 'a']) {
            //re += num[s[i] - 'a'];
            for (auto p : mp) {
                if (!vst[p.first - 'a'] && (!mp.count(s[i]) || p.second < mp[s[i]]))
                    re++;
            }
            vst[s[i] - 'a'] = true;
        }
    }

   // cout << "= " << re << '\n';

    return re + ms(bot, mid) + ms(mid + 1, top);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    
    cin >> s;

    cout << ms(0, s.length() - 1) << '\n';

 
    return 0;
}
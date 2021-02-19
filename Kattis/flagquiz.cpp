// case_considering
// https://open.kattis.com/problems/flagquiz
#include <bits/stdc++.h>
 
#define For(i, n) for (int i = 0; i < n; ++i)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array
 
using namespace std;
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;

int n;
map<string, int> mp;
vector<vector<int>> vec;
string pm[100000];
int sc[110];

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int idx = 0;

    string s;
    getline(cin, s);
    cin >> n;
    //cout << "n is " << n << '\n';
    getchar();
    For (i, n) {
        getline(cin, s);
        //cout << "the line " << s << '\n';
        vector<int> cur;
        s += ',';
        int prv = 0;
        For (j, s.length()) {
            if (s[j] == ',') {
                string part = s.substr(prv, j - prv);
                if (mp.count(part)) {
                    cur.push_back(mp[part]);
                }
                else {
                    //cout << idx << " -th is " << part << '\n';
                    mp[part] = idx;
                    cur.push_back(idx);
                    pm[idx] = part;
                    idx++;
                }
                prv = j + 2;
            }
        }
        vec.push_back(cur);
    }


    For (i, n) {
        int mx = 0;
        For (j, n) {
            int cnt = 0;
            For (k, vec[0].size()) {
                if (vec[i][k] != vec[j][k]) cnt++;
            }
            mx = max(mx, cnt);
        }
        sc[i] = mx;
    }

    int mn = MOD;
    For (i, n) {
        mn = min(mn, sc[i]);
    }

    // For (i, n) {
    //     cout << sc[i] << ' ' << pm[vec[i][0]] << '\n';
    // }
    // cout << '\n';

    For (i, n) {
        if (sc[i] == mn) {
            For (j, vec[i].size()) {
                cout << pm[vec[i][j]];
                if (j != vec[i].size() - 1) {
                    cout << ", ";
                }
            }
            cout << '\n';
        }
       
    }


    return 0;
}
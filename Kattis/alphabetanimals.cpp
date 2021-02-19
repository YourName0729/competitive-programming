// iteration
// https://open.kattis.com/problems/alphabetanimals
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
string arr[100010];
vector<int> b[26];
string s;

int answer() {
    int eli = MOD, can = MOD;
    for (auto i : b[s.back() - 'a']) {
        can = min(can, i);
        bool flg = 0;
        for (auto j : b[arr[i].back() - 'a']) {
            if (arr[j] != arr[i]) {
                //eli = min(eli, i);
                flg = 1;
                break;
            }
        }
        if (!flg)   eli = min(eli, i);
    }
    
    if (eli != MOD)  return n + eli;
    if (can != MOD)  return can;
    return -1;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    
    cin >> s >> n;
    For (i, n) {
        cin >> arr[i];
        b[arr[i].front() - 'a'].push_back(i);
        //e[ss.back() - 'a'].push_back(i);
    }

    int ans = answer();
    if (ans == -1) {
        cout << "?";
    }
    else if (ans >= n) {
        cout << arr[ans - n] << '!';
    }
    else {
        cout << arr[ans];
    }

    return 0;
}
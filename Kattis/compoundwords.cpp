//
// https://open.kattis.com/problems/compoundwords
#include <bits/stdc++.h>

#define For(i, n) for (int i = 0; i < n; i++)
#define Forcase int __t = 0; cin >> __t; while (__t--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ar array

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 2147483647;

set<string> st;
set<string> ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    string s;
    while (cin >> s) {
        //if (s == "0")   break;
        st.insert(s);
    }
    

    vector<string> vec;
    for (auto ss : st) {
        vec.push_back(ss);
    }

    For (i, vec.size()) {
        For (j, vec.size()) {
            if (i == j) continue;
            ans.insert(vec[i] + vec[j]);
        }
    }

    for (auto ss : ans) {
        cout << ss << '\n';
    }

    return 0;
}
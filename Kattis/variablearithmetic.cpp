//
// https://open.kattis.com/problems/variablearithmetic
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

map<string, int> vmp;

bool is_int(string& s, int& d) {
    d = 0;
    if (s[0] >= '0' && s[0] <= '9') {
        stringstream ss;
        ss << s;
        ss >> d;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    string in;
    while (getline(cin, in)) {
        if (in == "0")  break;

        stringstream ss;
        ss << in;
        vector<string> vec;
        string tmp;
        char op;
        ss >> tmp;
        if (!(ss >> op)) {
            int d;
            if (is_int(tmp, d)) {
                cout << d << '\n';
            }
            else if (vmp.count(tmp)) {
                cout << vmp[tmp] << '\n';
            }
            else {
                cout << tmp << '\n';
            }
            continue;
        }
        vec.push_back(tmp);
        if (op == '=') {
            int d;
            ss >> d;
            vmp[tmp] = d;
        } 
        else {
            ss >> tmp;
            vec.push_back(tmp);
            while (ss >> op >> tmp) {
                vec.push_back(tmp);
            }


            int sum = 0;
            vector<string> opt;
            for (auto s : vec) {
                int d;
                if (is_int(s, d)) {
                    sum += d;   
                }
                else if (vmp.count(s)) {
                    sum += vmp[s];
                }
                else {
                    opt.push_back(s);
                }
            }

            if (sum != 0 || opt.empty()) {
                cout << sum;
                if (!opt.empty()) cout << " + ";
            }
            For (i, opt.size()) {
                if (i != 0) cout << " + ";
                cout << opt[i];
            }
            cout << '\n';
        }
    }

    return 0;
}
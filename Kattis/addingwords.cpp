//
// https://open.kattis.com/problems/addingwords
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

map<string, int> mp;

string f(int ans) {
    for (auto e : mp) {
        if (e.second == ans) {
            return e.first;
        }
    }
    return "";
}

int main() {
    //fast;

    string s, dm;
    while (getline(cin, s)) {
        stringstream ss;
        ss << s;

        ss >> dm;
        if (dm == "def") {
            string var;
            int d;
            ss >> var >> d;

            mp[var] = d;
        } else if (dm == "calc") {
            bool gg = false;
            int ans;
            string oth;
            char op;
            ss >> oth;
            if (mp.count(oth)) {
                ans = mp[oth];
            } else {
                gg = true;
            }
            cout << oth << ' ';

            while (ss >> op) {
                cout << op << ' ';
                if (op == '=')  break;

                ss >> oth;
                cout << oth << ' ';
                if (!mp.count(oth)) {
                    gg = true;
                    continue;
                }
                if (op == '+')  ans += mp[oth];
                if (op == '-')  ans -= mp[oth];
            }

            string var = f(ans);
            if (gg || var == "") {
                cout << "unknown\n";
            } else {
                cout << var << '\n';
            }
        } else if (dm == "clear") {
            mp.clear();
        }
    }

    return 0;
}
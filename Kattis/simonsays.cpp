//
// https://open.kattis.com/problems/simonsays
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;

using namespace std;

int main() {
    //fast;

    forcase {
        string s;
        stringstream ss;

        getline(cin, s);
        ss << s;

        vector<string> v;
        string tmp;
        while (ss >> tmp) {
            v.push_back(tmp);
        }

        if (v.size() >= 2 && v[0] == "Simon" && v[1] == "says") {
            for (int i = 2; i < v.size(); i++) {
                cout << v[i] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}

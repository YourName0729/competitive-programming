//
// https://open.kattis.com/problems/simon
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>
#include <deque>

#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;
using namespace std;
const ll INF = 1000000010;
const ll MOD = 1000000007;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    //fast();

    forcase {
        string s;
        stringstream ss;
        getline(cin, s);
        
        ss << s;
        vector<string> vs;
        while (ss >> s) {
            vs.push_back(s);
        }

        if (vs.size() >= 2 && vs[0] == "simon" && vs[1] == "says") {
            for (int i = 2; i < vs.size(); i++) {
                cout << vs[i] << ' ';
            }
        }
        cout << '\n';
    }

    

    return 0;
}
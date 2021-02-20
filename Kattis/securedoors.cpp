// 
// https://open.kattis.com/problems/securedoors
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
#include <numeric>
#include <iomanip>
#include <set>

#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;
using namespace std;

const ll INF = 1000000010;
const ll MOD = 1000000007;

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n;
set<string> st;

int main() {
    //fast();

    cin >> n;
    string op, name;
    while (n--) {
        cin >> op >> name;
        if (op == "entry") {
            cout << name << " entered ";

            if (st.count(name)) {
                cout << "(ANOMALY)";
            } else {
                st.insert(name);
            }
        } else {
            cout << name << " exited ";
            if (!st.count(name)) {
                cout << "(ANOMALY)";
            } else {
                st.erase(name);
            }
        }
        cout << '\n';
    }

    return 0;
}
// implement
// https://open.kattis.com/problems/teque
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <utility>
#include <queue>
#include <iomanip>
#include <deque>

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9

using ull = unsigned long long;
using ll = long long;
using namespace std;

int n;
deque<int> dq1, dq2;

void pb(int val) {
    dq2.push_back(val);
    if (dq2.size() > dq1.size()) {
        dq1.push_back(dq2.front());
        dq2.pop_front();
    }
}
void pf(int val) {
    dq1.push_front(val);
    if (dq1.size() == dq2.size() + 2) {
        dq2.push_front(dq1.back());
        dq1.pop_back();
    }
}
void pm(int val) {
    if (dq1.size() == dq2.size()) {
        dq1.push_back(val);
    } else {
        dq2.push_front(val);
    }
}
int get(int idx) {
    if (idx < dq1.size()) {
        return dq1[idx];
    }
    return dq2[idx - dq1.size()];
}

int main() {

    string s;
    int q;

    cin >> n;
    For (i, n) {
        cin >> s >> q;
        if (s == "push_back") {
            pb(q);
        } else if (s == "push_front") {
            pf(q);
        } else if (s == "push_middle") {
            pm(q);
        } else {
            cout << get(q) << '\n';
        }
    }

    return 0;
}
// brute_force
// https://open.kattis.com/problems/hanjie
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
#include <set>

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9
#define EPS 1e-9

using ull = unsigned long long;
using ll = long long;
using namespace std;

int r, c;
vector<int> R[6], C[6];
bool bd[6][6];

void nxt(int& x, int& y) {
    if (y == c - 1) {
        x++;
        y = 0;
    } else {
        y++;
    }
}

bool legal(vector<int>& cur, vector<int>& org) {
    // cout << "legal:\n";
    // cout << "    ";
    // For (i, cur.size()) {
    //     cout << cur[i] << ' ';
    // }
    // cout << '\n';
    // cout << "    ";
    // For (i, org.size()) {
    //     cout << org[i] << ' ';
    // }
    // cout << '\n';

    if (cur.size() == 0)    return true;
    if (cur.size() > org.size())    return false;
    For (i, cur.size() - 1) {
        if (cur[i] != org[i])   return false;
    }
    return cur.back() <= org[cur.size() - 1];
}

bool match(vector<int>& cur, vector<int>& org) {
    // cout << "match:\n";
    // cout << "    ";
    // For (i, cur.size()) {
    //     cout << cur[i] << ' ';
    // }
    // cout << '\n';
    // cout << "    ";
    // For (i, org.size()) {
    //     cout << org[i] << ' ';
    // }
    // cout << '\n';

    if (cur.size() != org.size())   return false;
    For (i, cur.size()) {
        if (cur[i] != org[i])   return false;
    }
    return true;
}

void make(int x, int y, vector<int>& curR, vector<int>& curC) {
    curR.clear();
    curC.clear();
    int cnt;

    cnt = 0;
    For (i, r) {
        if (bd[i][y]) {
            if (cnt == 0) {
                curC.push_back(1);
            } else {
                curC.back()++;
            }
            cnt++;
        } else {
            cnt = 0;
        }
    }

    cnt = 0;
    For (i, c) {
        if (bd[x][i]) {
            if (cnt == 0) {
                curR.push_back(1);
            } else {
                curR.back()++;
            }
            cnt++;
        } else {
            cnt = 0;
        }
    }

    //cout << "make ok\n";
}

int ans = 0;
void go(int x, int y) {
    if (x == r && y == 0) {
        ans++;
        return;
    }

    // cout << "consider " << x << ", " << y << '\n';
    // For (i, r) {
    //     For (j, c) {
    //         cout << bd[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    vector<int> curR, curC;

    //cout << "consider " << x << ", " << y << " = 0\n";
    make(x, y, curR, curC);
    if (((x == r - 1)? match(curC, C[y]) : legal(curC, C[y])) && 
        ((y == c - 1)? match(curR, R[x]) : legal(curR, R[x]))) {
        //cout << "can put " << x << ", " << y << " = 0\n";
        int a = x, b = y;
        nxt(a, b);
        go(a, b);
    } else {
        //cout << "cant put " << x << ", " << y << " = 0\n";
    }


    //cout << "consider " << x << ", " << y << " = 1\n";
    bd[x][y] = true;
    make(x, y, curR, curC);
    if (((x == r - 1)? match(curC, C[y]) : legal(curC, C[y])) && 
        ((y == c - 1)? match(curR, R[x]) : legal(curR, R[x]))) {
        //cout << "can put " << x << ", " << y << " = 1\n";
        int a = x, b = y;
        nxt(a, b);
        go(a, b);
    } else {
        //cout << "cant put " << x << ", " << y << " = 1\n";
    }
    bd[x][y] = false;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n;
    cin >> r >> c;
    For (i, r) {
        cin >> n;
        For (j, n) {
            int tmp;
            cin >> tmp;
            R[i].push_back(tmp);
        }
    }
    For (i, c) {
        cin >> n;
        For (j, n) {
            int tmp;
            cin >> tmp;
            C[i].push_back(tmp);
        }
    }

    go(0, 0);

    cout << ans << '\n';
    
    return 0;
}
// number_theory
// https://open.kattis.com/problems/inversefactorial
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

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

double pfx_log[1000010];
int val[1000010];

bool check(int cur) {
    int i = 0;
    while (cur) {
        cout << cur % 10 << ' ' << val[i] << '\n';
        if (cur % 10 == val[i]) {
            cur /= 10;
            i++;
        } else {
            return false;
        }
    }
    return true;
}

int dgt(int n) {
    return int(pfx_log[n]) + 1;
}

int main() {
    //fast();

    for (int i = 2; i < 1000001; i++) {
        pfx_log[i] = pfx_log[i - 1] + log10(i);
    }

    int n;
    string s;
    cin >> s;
    n = s.size();
    For (i, n) {
        val[i] = s[i] - '0';
    }

    if (n <= 8) {
        int in = stoi(s);
        int cur = 1;
        for (int i = 1; i <= 11; i++) {
            cur *= i;
            if (in == cur) {
                cout << i << '\n';
                break;
            }    
        }
    } else {
        int l = 11, r = 1000000;
        while (l < r) {
            int mid = (l + r) / 2;
            if (dgt(mid) == n) {
                cout << mid << '\n';
                break;
            } else if (dgt(mid) > n) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (dgt(l) == n) {
            cout << l << '\n';
        } else if (dgt(r) == n) {
            cout << r << '\n';
        }
    }
    

    return 0;
}

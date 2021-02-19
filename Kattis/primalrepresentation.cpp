// prime_factoring
// https://open.kattis.com/problems/primalrepresentation
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



int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n;
    vector<int> p, q;
    while (cin >> n) {
        p.clear();
        q.clear();

        if (n < 0) {
            cout << -1 << ' ';
            n *= -1;
        }

        int cur = 2;
        while (n != 1) {
            if (cur > sqrt(n) + 1) {
                p.push_back(n);
                q.push_back(1);
                break;
            }

            if (n % cur == 0) {
                int cnt = 0;
                while (n % cur == 0) {
                    cnt++;
                    n /= cur;
                }

                p.push_back(cur);
                q.push_back(cnt);
            } else {
                cur++;
            }
        }

        For (i, p.size()) {
            cout << p[i];
            if (q[i] != 1) {
                cout << '^' << q[i];
            }
            cout << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
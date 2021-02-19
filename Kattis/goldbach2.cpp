//
// https://open.kattis.com/problems/goldbach2
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

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9

using ull = unsigned long long;
using ll = long long;
using namespace std;

int nxtPrm[100010];
vector<int> prm;

int main() {

    for (int i = 2; i < 100000; i++) {
        nxtPrm[i] = i + 1;
    }

    for (int i = 2; i < 50010; i++) {
        int cur = i;
        while (cur < 50010) {
            if (nxtPrm[cur] % i == 0) {
                nxtPrm[cur] = nxtPrm[nxtPrm[cur]];
            } else {
                cur = nxtPrm[cur];
            }
        }
    }

    int cur = 2;
    while (cur < 50010) {
        prm.push_back(cur);
        cur = nxtPrm[cur];
    }

    int n;
    cin >> n;
    For (i, n) {
        int q;
        cin >> q;

        int l = 0, r = prm.size() - 1;
        vector<int> ans1, ans2;

        while (l <= r) {
            if (prm[l] + prm[r] == q) {
                ans1.push_back(prm[l]);
                ans2.push_back(prm[r]);
                l++; r--;
            } else if (prm[l] + prm[r] < q) {
                l++;
            } else {
                r--;
            }
        }

        cout << q << " has " << ans1.size() << " representation(s)\n";
        For (i, ans1.size()) {
            cout << ans1[i] << '+' << ans2[i] << '\n';
        }
    }

    return 0;
}
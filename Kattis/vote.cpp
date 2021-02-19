//
// https://open.kattis.com/problems/vote
#include <vector>
#include <algorithm>
#include <iostream>

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

using ull = unsigned long long;
using ll = long long;
using namespace std;


int main() {

    Forcase {
        int n, sum = 0, mx = -1;
        vector<int> vec;

        cin >> n;
        For (i, n) {
            int tmp;
            cin >> tmp;
            vec.push_back(tmp);
            sum += tmp;

            mx = max(mx, tmp);
        }

        vector<int> mxi;
        For (i, n) {
            if (vec[i] == mx) {
                mxi.push_back(i);
            }
        }

        if (mxi.size() != 1) {
            cout << "no winner\n";
        } else if (mx * 2 > sum) {
            cout << "majority winner " << mxi[0] + 1 << '\n';
        } else {
            cout << "minority winner " << mxi[0] + 1 << '\n';
        }
    }

    return 0;
}
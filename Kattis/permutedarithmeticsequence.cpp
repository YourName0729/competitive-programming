//
// https://open.kattis.com/problems/permutedarithmeticsequence
#include <vector>
#include <algorithm>
#include <iostream>

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

using ull = unsigned long long;
using ll = long long;
using namespace std;

bool permute(vector<int>& vec) {
    if (vec.size() <= 2)    return true;

    int diff = vec[1] - vec[0];
    For (i, vec.size() - 1) {
        if (vec[i + 1] - vec[i] != diff)    return false;
    }
    return true;
}

int main() {

    Forcase {
        int n;
        vector<int> vec;

        cin >> n;
        For (i, n) {
            int tmp;
            cin >> tmp;
            vec.push_back(tmp);
        }

        if (permute(vec)) {
            cout << "arithmetic\n";
        } else {
            sort(vec.begin(), vec.end());

            if (permute(vec)) {
                cout << "permuted arithmetic\n";
            } else {
                cout << "non-arithmetic\n";
            }
        }
    }

    return 0;
}
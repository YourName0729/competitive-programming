//
// https://open.kattis.com/problems/bitbybit
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

int n;
int arr[100];

int And[3][3] = {
    {-1, 0, -1},
    {0, 0, 0},
    {-1, 0, 1}
};
int Or[3][3] = {
    {-1, -1, 1},
    {-1, 0, 1},
    {1, 1, 1}
};


int main() {

    while (cin >> n && n != 0) {
        For (i, 32) {
            arr[i] = -1;
        }

        int q1, q2;
        For (i, n) {
            string s;
            cin >> s;

            if (s == "SET") {
                cin >> q1;
                arr[q1] = 1;
            } else if (s == "CLEAR") {
                cin >> q1;
                arr[q1] = 0;
            } else if (s == "AND") {
                cin >> q1 >> q2;
                arr[q1] = And[arr[q1] + 1][arr[q2] + 1];
            } else {
                cin >> q1 >> q2;
                arr[q1] = Or[arr[q1] + 1][arr[q2] + 1];
            }
        }

        for (int i = 31; i >= 0; i--) {
            if (arr[i] == -1) {
                cout << '?';
            } else {
                cout << arr[i];
            }
        }
        cout << '\n';
    }

    return 0;
}
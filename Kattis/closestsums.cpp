// brute_force
// https://open.kattis.com/problems/closestsums
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>

#define Forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

using ull = unsigned long long;
using ll = long long;
using namespace std;

int arr[1010];

int main() {


    int n, m, t = 1;
    while (cin >> n) {
        cout << "Case " << t++ << ":\n";
        For (i, n) {
            cin >> arr[i];
        }

        cin >> m;
        For (i, m) {
            int q, ans = -1;
            cin >> q;
            For (j, n) {
                For (k, n) {
                    if (j == k) continue;
                    if (ans == -1 || abs(ans - q) > abs(arr[j] + arr[k] - q)) {
                        ans = arr[j] + arr[k];
                    }
                }
            }

            cout << "Closest sum to " << q << " is " << ans << ".\n";
        }        
    }


    return 0;
}
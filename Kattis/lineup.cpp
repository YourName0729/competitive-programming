//
// https://open.kattis.com/problems/lineup
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

#define Forcase int __t;cin>>__t;for(int cases=1;cases<=__t;cases++)
#define For(i, n) for(int i=0;i<n;i++)
#define Fore(e, arr) for(auto e:arr)

#define INF 1e9
#define LINF 1e18
#define EPS 1e-9

using ull = unsigned long long;
using ll = long long;
using namespace std;

int n;
string arr[30];

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n;
    cin >> n;
    For (i, n) {
        cin >> arr[i];
    }

    bool inc = true;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])    inc = false;
    }

    bool dec = true;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1])    dec = false;
    }

    if (inc) {
        cout << "INCREASING\n";
    } else if (dec) {
        cout << "DECREASING\n";
    } else {
        cout << "NEITHER\n";
    }

    return 0;
}

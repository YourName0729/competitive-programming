//
// https://open.kattis.com/problems/ptice
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
#include <functional>

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
char arr[110];

char adr(int idx) {
    char cc[3] = {'A', 'B', 'C'};
    return cc[idx % 3];
}
char bru(int idx) {
    char cc[4] = {'B', 'A', 'B', 'C'};
    return cc[idx % 4];
}
char gor(int idx) {
    char cc[6] = {'C', 'C', 'A', 'A', 'B', 'B'};
    return cc[idx % 6];
}

int score(function<char(int)> ans) {
    int re = 0;
    For (i, n) {
        //cout << "? " << arr[i] << ' ' << ans(i) << '\n';
        if (arr[i] == ans(i)) {
            re++;
        }
    }
    return re;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin >> n;
    For (i, n) {
        cin >> arr[i];
    }

    int a = score(adr), b = score(bru), c = score(gor);
    int ans = max(a, max(b, c));

    cout << ans << '\n';
    if (a == ans) {
        cout << "Adrian\n";
    }
    if (b == ans) {
        cout << "Bruno\n";
    }
    if (c == ans) {
        cout << "Goran\n";
    }

    

    return 0;
}

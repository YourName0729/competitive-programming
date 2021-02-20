//
// https://open.kattis.com/problems/bookingaroom
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
#include <numeric>
#include <iomanip>

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

bool arr[110];
int n, r;
void go() {
    for (int i = 1; i <= r; i++) {
        if (!arr[i]) {
            cout << i << '\n';
            return;
        }
    }
    cout << "too late\n";
}

int main() {
    //fast();

    
    cin >> r >> n;

    For (i, n) {
        int tmp;
        cin >> tmp;
        arr[tmp] = true;
    }

    go();

    return 0;
}
//
// https://open.kattis.com/problems/flexible
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

int arr[110];
bool vst[110];

int main() {
    //fast();

    int w, p;
    cin >> w >> p;
    For (i, p) {
        cin >> arr[i + 1];
    }
    arr[0] = 0;
    arr[p + 1] = w;
    p += 2;

    // For (i, p) {
    //     cout << arr[i] << ' ';
    // }
    // cout << '\n';

    For (i, p) {
        for (int j = i + 1; j < p; j++) {
            vst[arr[j] - arr[i]] = true;
        }
    }
    for (int i = 1; i <= w; i++) {
        if (vst[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}

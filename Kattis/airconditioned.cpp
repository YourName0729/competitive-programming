// greedy
// https://open.kattis.com/problems/airconditioned
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

struct I {
    int a, b;
};
bool cmp(I& a, I& b) {
    if (a.a == b.a) return a.b < b.b;
    return a.a < b.a;
}

int n;
I arr[200];
bool vst[200];

bool vstAll() {
    For (i, n) {
        if (!vst[i])    return false;
    }
    return true;
}

int main() {
    //fast();
    
    cin >> n;
    For (i, n) {
        cin >> arr[i].a >> arr[i].b;
    }
    sort(arr, arr + n, cmp);

    int ans = 0;
    while (!vstAll()) {
        int ll = -1;
        For (i, n) {
            if (!vst[i] && (ll == -1 || arr[i].b < ll)) {
                ll = arr[i].b;
            }
        }

        ans++;
        For (i, n) {
            if (arr[i].a <= ll && ll <= arr[i].b) {
                vst[i] = true;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
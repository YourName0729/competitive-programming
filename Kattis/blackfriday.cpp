//
// https://open.kattis.com/problems/blackfriday
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

int n;
int arr[110];
bool vst[110];

int x() {
    int at = -1;
    For (i, n) {
        if (vst[i]) continue;

        if (at == -1 || arr[at] < arr[i]) {
            at = i;
        }
    }
    return at;
}

int count(int at) {
    int re = 0;
    For (i, n) {
        if (vst[i]) continue;

        if (arr[i] == arr[at])  re++;
    }
    return re;
}

void go() {
    while (true) {
        int at = x();
        if (at == -1) {
            cout << "none\n";
            return;
        }

        int c = count(at);
        if (c == 1) {
            cout << at + 1 << '\n';
            return;
        }

        For (i, n) {
            if (arr[i] == arr[at]) {
                vst[i] = true;
            }
        }
    }
}

int main() {
    //fast();

    cin >> n;
    For (i, n) {
        cin >> arr[i];
    }
    go();

    return 0;
}
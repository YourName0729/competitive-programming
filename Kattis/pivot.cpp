//
// https://open.kattis.com/problems/pivot
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>

#define forcase int __t;cin>>__t;getchar();for(int ___t=1;___t<=__t;___t++)
#define For(i, n) for(int i=0;i<n;i++)

using ll = long long;
using namespace std;
const ll INF = 1000000010;
const ll MOD = 1000000007;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n;
int arr[100010];
int pfx_max[100010];
int sfx_min[100010];

int main() {
    //fast();

    cin >> n;
    For (i, n) {
        cin >> arr[i];
    }

    int mx = arr[0];
    For (i, n) {
        pfx_max[i] = max(mx, arr[i]);
        mx = max(mx, arr[i]);
    }

    int mn = arr[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        sfx_min[i] = min(mn, arr[i]);
        mn = min(mn, arr[i]);
    }

    int ans = 0;
    For (i, n) {
        bool notok = false;
        if (i != 0) {
            notok = notok || (pfx_max[i - 1] > arr[i]);
        }
        if (i != n - 1) {
            notok = notok || (arr[i] > sfx_min[i + 1]);
        }
        if (!notok) ans++;
    }
    cout << ans << '\n';

    return 0;
}
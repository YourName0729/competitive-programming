// dp LIS
// https://open.kattis.com/problems/poklon
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define forcase int __t;cin >> __t;while (__t--)

using namespace std;

struct I {
    int a, b;
};

int n;
I arr[100010];
int dp[100010];

vector<int> vec;

bool cmp(I a, I b) {
    if (a.a == b.a) return a.b < b.b;
    return a.a > b.a;
}

int bs(int tar) {
    int l = 0, r = vec.size() - 1;
    while (l != r) {
        int mid = (l + r) / 2;

        if (vec[mid] > tar) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    return l;
}

void LIS() {
    for (int i = 0; i < n; i++) {
        if (vec.size() == 0 || arr[i].b >= vec[vec.size() - 1]) {
            vec.push_back(arr[i].b);
            dp[i] = vec.size();
        } else {
            int loc = bs(arr[i].b);

            dp[i] = loc + 1;
            vec[loc] = arr[i].b;
        }
    }
}

void REV() {
    /*for (int i = 0; i < n; i++) {
        cout << dp[i] << '\n';
    }*/

    int l = vec.size(), num = 1000000;
    for (int i = n - 1; i >= 0; i--) {
        if (dp[i] == l && arr[i].b <= num) {
            cout << arr[i].a << ' ' << arr[i].b << '\n';

            l--;
            num = arr[i].b;
        }
    }
}

int main() {
    fast;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].a >> arr[i].b;
    }

    sort(arr, arr + n, cmp);

    LIS();
    cout << vec.size() << '\n';

    REV();

    return 0;
}

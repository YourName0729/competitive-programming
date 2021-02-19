// binary_searching
// https://open.kattis.com/problems/paintbuckets
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define forcase int __t;cin >> __t;while (__t--)

using namespace std;

struct D {
    int h, v;
};

bool cmp(const D& d1, const D& d2) {
    return d1.h < d2.h;
}

int n, q;
D arr[200010];

int query(int h) {
    int l = 0, r = n - 1;

    while (l != r) {
        int mid = (l + r) / 2;
        if (arr[mid].h < h) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    int it = l;
    int re = 0;
    while (it != n && arr[it].h - h <= 2000) {
        re += arr[it].v;
        it++;
    }
    return re;
}

int main() {
    fast;

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].h >> arr[i].v;
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++) {
        arr[i].h += 1000;
    }

    for (int i = 0; i < q; i++) {
        int h, v;
        cin >> h >> v;
        int ans = query(h);

        if (ans >= v) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}
//
// https://open.kattis.com/problems/synchronizinglists
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

struct Idx {
    int val, idx, v2;
    Idx(int a, int b) : val(a), idx(b) {}
    Idx() : val(0), idx(0) {}
};

bool cmp(const Idx& a, const Idx& b) {
    return a.val < b.val;
}
bool cmp2(const Idx& a, const Idx& b) {
    return a.idx < b.idx;
}

int n;
Idx arr[5010];
int arr2[5010];

int main() {
    
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i].val;
            arr[i].idx = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> arr2[i];
        }

        sort(arr, arr + n, cmp);
        sort(arr2, arr2 + n);

        for (int i = 0; i < n; i++) {
            arr[i].v2 = arr2[i];
        }
        sort(arr, arr + n, cmp2);

        for (int i = 0; i < n; i++) {
            cout << arr[i].v2 << '\n';
        }
        cout << '\n';
    }

    return 0;
}

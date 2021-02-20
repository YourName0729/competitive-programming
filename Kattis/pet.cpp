//
// https://open.kattis.com/problems/pet
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

int main() {
    int a[5] = {0};
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        int sum = 0, tmp;
        for (int i = 0; i < 4; i++) {
            cin >> tmp;
            sum += tmp;
        }
        a[i] = sum;

        if (a[i] >= a[ans]) {
            ans = i;
        }
    }
    cout << ans + 1 << ' ' << a[ans] << '\n';

    return 0;
}

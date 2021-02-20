//
// https://open.kattis.com/problems/sibice
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
    int n, w, h;
    cin >> n >> w >> h;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp * tmp <= w * w + h * h) {
            cout << "DA\n";
        } else {
            cout << "NE\n";
        }
    }

    return 0;
}

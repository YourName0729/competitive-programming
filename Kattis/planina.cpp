//
// https://open.kattis.com/problems/planina
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
    int n;
    cin >> n;
    int tmp = 2;
    for (int i = 0; i < n; i++) {
        tmp = 2 * tmp - 1;
    }
    cout << tmp * tmp << '\n';

    return 0;
}

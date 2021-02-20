//
// https://open.kattis.com/problems/skocimis
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

int a[3];


int main() {
    
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    sort(a, a + 3);

    cout << max(a[2] - a[1] - 1, a[1] - a[0] - 1) << '\n';

    return 0;
}

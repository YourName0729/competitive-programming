//
// https://open.kattis.com/problems/mixedfractions
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
    
    int a, b;
    while (cin >> a >> b && !(a == 0 && b == 0)) {
        cout << a / b << ' ' << a % b << " / " << b << '\n';
    }

    return 0;
}

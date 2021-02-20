//
// https://open.kattis.com/problems/tarifa
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
    
    int n, x, sum = 0, tmp;

    cin >> x >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        sum += tmp;
    }

    cout << x + n * x - sum << '\n';

    return 0;
}

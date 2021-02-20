//
// https://open.kattis.com/problems/heartrate
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
    while (n--) {
        double b, p;
        cin >> b >> p;
        cout << fixed << (b - 1) * 60 / p << ' ' << b * 60 / p << ' ' << (b + 1) * 60 / p << '\n';
    }
    

    return 0;
}

//
// https://open.kattis.com/problems/romans
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
    
    double n;
    cin >> n;
    cout <<  (int)round(n * 5280.0 / 4.854) << '\n';
    

    return 0;
}

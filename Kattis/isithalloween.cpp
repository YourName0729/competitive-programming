//
// https://open.kattis.com/problems/isithalloween
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
    string s;
    int d;
    cin >> s >> d;

    if (s == "OCT" && d == 31) {
        cout << "yup\n";
    } else if (s == "DEC" && d == 25) {
        cout << "yup\n";
    }else {
        cout << "nope\n";
    }

    return 0;
}
